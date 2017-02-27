﻿/***********************************************************************************
**
** GumpCombatBook.cpp
**
** Copyright (C) December 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#include "GumpCombatBook.h"
#include "GumpAbility.h"
#include "../PressedObject.h"
#include "../ClickObject.h"
#include "../OrionUO.h"
#include "../Managers/MouseManager.h"
#include "../Managers/GumpManager.h"
#include "../Managers/ClilocManager.h"
#include "../Managers/PacketManager.h"
#include "../OrionWindow.h"
#include "../ToolTip.h"
//----------------------------------------------------------------------------------
CGumpCombatBook::CGumpCombatBook(const int &x, const int &y)
: CGump(GT_COMBAT_BOOK, 0, x, y), m_DictionaryPagesCount(6), m_PagesCount(37),
m_AbilityCount(MAX_ABILITIES_COUNT), m_PrevPage(NULL), m_NextPage(NULL)
{
	m_Draw2Page = true;

	if (g_PacketManager.ClientVersion < CV_7000)
	{
		if (g_PacketManager.ClientVersion >= CV_500A)
			m_AbilityCount = 29;
		else
		{
			m_AbilityCount = 13;
			m_DictionaryPagesCount = 2;
		}
	}

	m_PagesCount = m_DictionaryPagesCount + (m_AbilityCount * 2);
}
//----------------------------------------------------------------------------------
CGumpCombatBook::~CGumpCombatBook()
{
}
//----------------------------------------------------------------------------------
USHORT_LIST CGumpCombatBook::GetItemsList(const uchar &index)
{
	USHORT_LIST list;

	switch (index)
	{
		case 0:
		{
			list.push_back(3908);
			list.push_back(5048);
			list.push_back(3935);
			list.push_back(5119);
			list.push_back(9927);
			list.push_back(5181);
			list.push_back(5040);
			list.push_back(5121);
			list.push_back(3939);
			list.push_back(9932);
			list.push_back(11554);
			list.push_back(16497);
			list.push_back(16502);
			list.push_back(16494);
			list.push_back(16491);
			break;
		}
		case 1:
		{
			list.push_back(3779);
			list.push_back(5115);
			list.push_back(3912);
			list.push_back(3910);
			list.push_back(5185);
			list.push_back(9924);
			list.push_back(5127);
			list.push_back(5040);
			list.push_back(3720);
			list.push_back(5125);
			list.push_back(11552);
			list.push_back(16499);
			list.push_back(16498);
			break;
		}
		case 2:
		{
			list.push_back(5048);
			list.push_back(3912);
			list.push_back(5183);
			list.push_back(5179);
			list.push_back(3933);
			list.push_back(5113);
			list.push_back(3722);
			list.push_back(9930);
			list.push_back(3920);
			list.push_back(11556);
			list.push_back(16487);
			list.push_back(16500);
			break;
		}
		case 3:
		{
			list.push_back(5050);
			list.push_back(3914);
			list.push_back(3935);
			list.push_back(3714);
			list.push_back(5092);
			list.push_back(5179);
			list.push_back(5127);
			list.push_back(5177);
			list.push_back(9926);
			list.push_back(4021);
			list.push_back(10146);
			list.push_back(11556);
			list.push_back(11560);
			list.push_back(5109);
			list.push_back(16500);
			list.push_back(16495);
			break;
		}
		case 4:
		{
			list.push_back(5111);
			list.push_back(3718);
			list.push_back(3781);
			list.push_back(3908);
			list.push_back(3573);
			list.push_back(3714);
			list.push_back(3933);
			list.push_back(5125);
			list.push_back(11558);
			list.push_back(11560);
			list.push_back(5109);
			list.push_back(9934);
			list.push_back(16493);
			list.push_back(16494);
			break;
		}
		case 5:
		{
			list.push_back(3918);
			list.push_back(3914);
			list.push_back(9927);
			list.push_back(3573);
			list.push_back(5044);
			list.push_back(3720);
			list.push_back(9930);
			list.push_back(5117);
			list.push_back(16501);
			list.push_back(16495);
			break;
		}
		case 6:
		{
			list.push_back(3718);
			list.push_back(5187);
			list.push_back(3916);
			list.push_back(5046);
			list.push_back(5119);
			list.push_back(9931);
			list.push_back(3722);
			list.push_back(9929);
			list.push_back(9933);
			list.push_back(10148);
			list.push_back(10153);
			list.push_back(16488);
			list.push_back(16493);
			list.push_back(16496);
			break;
		}
		case 7:
		{
			list.push_back(5111);
			list.push_back(3779);
			list.push_back(3922);
			list.push_back(9928);
			list.push_back(5121);
			list.push_back(9929);
			list.push_back(11553);
			list.push_back(16490);
			list.push_back(16488);
			break;
		}
		case 8:
		{
			list.push_back(3910);
			list.push_back(9925);
			list.push_back(9931);
			list.push_back(5181);
			list.push_back(9926);
			list.push_back(5123);
			list.push_back(3920);
			list.push_back(5042);
			list.push_back(16499);
			list.push_back(16502);
			list.push_back(16496);
			list.push_back(16491);
			break;
		}
		case 9:
		{
			list.push_back(5117);
			list.push_back(9932);
			list.push_back(9933);
			list.push_back(16492);
			break;
		}
		case 10:
		{
			list.push_back(5050);
			list.push_back(3918);
			list.push_back(5046);
			list.push_back(9924);
			list.push_back(9925);
			list.push_back(5113);
			list.push_back(3569);
			list.push_back(9928);
			list.push_back(3939);
			list.push_back(5042);
			list.push_back(16497);
			list.push_back(16498);
			break;
		}
		case 11:
		{
			list.push_back(3781);
			list.push_back(5187);
			list.push_back(5185);
			list.push_back(5092);
			list.push_back(5044);
			list.push_back(3922);
			list.push_back(5123);
			list.push_back(4021);
			list.push_back(11553);
			list.push_back(16490);
			break;
		}
		case 12:
		{
			list.push_back(5115);
			list.push_back(5183);
			list.push_back(3916);
			list.push_back(5177);
			list.push_back(3569);
			list.push_back(10157);
			list.push_back(11559);
			list.push_back(9934);
			list.push_back(16501);
			break;
		}
		case 13:
		{
			list.push_back(10146);
			break;
		}
		case 14:
		{
			list.push_back(10148);
			list.push_back(10150);
			list.push_back(10151);
			break;
		}
		case 15:
		{
			list.push_back(10147);
			list.push_back(10158);
			list.push_back(10159);
			list.push_back(11557);
			break;
		}
		case 16:
		{
			list.push_back(10151);
			list.push_back(10157);
			list.push_back(11561);
			break;
		}
		case 17:
		{
			list.push_back(10152);
			break;
		}
		case 18:
		case 20:
		{
			list.push_back(10155);
			break;
		}
		case 19:
		{
			list.push_back(10152);
			list.push_back(10153);
			list.push_back(10158);
			list.push_back(11554);
			break;
		}
		case 21:
		{
			list.push_back(10149);
			break;
		}
		case 22:
		{
			list.push_back(10149);
			list.push_back(10159);
			break;
		}
		case 23:
		{
			list.push_back(11555);
			list.push_back(11558);
			list.push_back(11559);
			list.push_back(11561);
			break;
		}
		case 24:
		case 27:
		{
			list.push_back(11550);
			break;
		}
		case 25:
		{
			list.push_back(11551);
			break;
		}
		case 26:
		{
			list.push_back(11551);
			list.push_back(11552);
			break;
		}
		case 28:
		{
			list.push_back(11557);
			break;
		}
		case 29:
		{
			list.push_back(16492);
			break;
		}
		case 30:
		{
			list.push_back(16487);
			break;
		}
		default:
			break;
	}

	return list;
}
//----------------------------------------------------------------------------------
void CGumpCombatBook::InitToolTip()
{
	if (m_Minimized)
	{
		g_ToolTip.Set(L"Double click to maximize book gump");
		return;
	}

	uint serial = g_SelectedObject.Serial;

	if (m_Page >= m_DictionaryPagesCount)
	{
		if (serial >= ID_GCB_ICON)
			g_ToolTip.Set(g_ClilocManager.Cliloc(g_Language)->GetW(1061693 + (serial - ID_GCB_ICON)), 150);
	}
	else
	{
		if (serial == ID_GCB_ICON_FIRST)
			g_ToolTip.Set(g_ClilocManager.Cliloc(g_Language)->GetW(1028838 + (g_AbilityList[g_Ability[0]] & 0xFF)), 80);
		else if (serial == ID_GCB_ICON_SECOND)
			g_ToolTip.Set(g_ClilocManager.Cliloc(g_Language)->GetW(1028838 + (g_AbilityList[g_Ability[1]] & 0xFF)), 80);
	}
}
//----------------------------------------------------------------------------
void CGumpCombatBook::PrepareContent()
{
	if (g_PressedObject.LeftGump() == this && m_Page < m_DictionaryPagesCount && (g_PressedObject.LeftSerial == ID_GCB_ICON_FIRST || g_PressedObject.LeftSerial == ID_GCB_ICON_SECOND))
	{
		WISP_GEOMETRY::CPoint2Di offset = g_MouseManager.LeftDroppedOffset();

		if ((abs(offset.X) >= DRAG_PIXEL_RANGE || abs(offset.Y) >= DRAG_PIXEL_RANGE) || (g_MouseManager.LastLeftButtonClickTimer + g_MouseManager.DoubleClickDelay < g_Ticks))
		{
			g_GumpManager.AddGump(new CGumpAbility(g_PressedObject.LeftSerial == ID_GCB_ICON_SECOND, g_MouseManager.Position.X - 20, g_MouseManager.Position.Y - 20));

			g_OrionWindow.EmulateOnLeftMouseButtonDown();
		}
	}
}
//----------------------------------------------------------------------------
void CGumpCombatBook::UpdateContent()
{
	m_PrevPage = NULL;
	m_NextPage = NULL;

	Clear();

	Add(new CGUIPage(-1));

	if (m_Minimized)
	{
		Add(new CGUIGumppic(0x2B05, 0, 0));

		return;
	}

	Add(new CGUIGumppic(0x2B02, 0, 0));

	Add(new CGUIHitBox(ID_GCB_BUTTON_MINIMIZE, 6, 100, 16, 16, true));

	int offs = 0;

	IFOR(page, 0, m_DictionaryPagesCount)
	{
		Add(new CGUIPage(page));

		int indexX = 96;
		int dataX = 52;
		int y = 0;
		int spellsOnPage = 9;

		if (page % 2)
		{
			indexX = 259;
			dataX = 215;
			spellsOnPage = 4;
		}

		CGUIText *text = (CGUIText*)Add(new CGUIText(0x0288, indexX, 6));
		text->CreateTextureA(6, "INDEX");

		IFOR(i, 0, spellsOnPage)
		{
			if (offs >= m_AbilityCount)
				break;

			CGUITextEntry *entry = (CGUITextEntry*)Add(new CGUITextEntry(ID_GCB_ICON + offs, 0x0288, 0, 0, dataX, 42 + y, 0, false, 9));
			entry->m_Entry.SetText(m_AbilityName[offs]);
			entry->CheckOnSerial = true;
			entry->ReadOnly = true;

			CGUIHitBox *box = (CGUIHitBox*)Add(new CGUIHitBox(ID_GCB_ICON + offs, dataX, 42 + y, 100, 16, true));
			box->MoveOnDrag = true;

			y += 15;

			offs++;
		}

		if (spellsOnPage == 4)
		{
			CGUIGumppic *icon = (CGUIGumppic*)Add(new CGUIGumppic(0x5200 + (g_AbilityList[g_Ability[0]] & 0x00FF), 215, 105));
			icon->Serial = ID_GCB_ICON_FIRST;

			text = (CGUIText*)Add(new CGUIText(0x0288, 265, 105));
			text->CreateTextureA(6, "Primary Ability Icon", 80);

			icon = (CGUIGumppic*)Add(new CGUIGumppic(0x5200 + (g_AbilityList[g_Ability[1]] & 0x00FF), 215, 150));
			icon->Serial = ID_GCB_ICON_SECOND;

			text = (CGUIText*)Add(new CGUIText(0x0288, 265, 150));
			text->CreateTextureA(6, "Secondary Ability Icon", 80);
		}
	}

	int page = m_DictionaryPagesCount;

	IFOR(i, 0, m_AbilityCount)
	{
		Add(new CGUIPage(page));
		page += 2;

		CGUIGumppic *icon = (CGUIGumppic*)Add(new CGUIGumppic(0x5200 + i, 62, 40));
		icon->Serial = ID_GCB_ICON + i;
		icon->MoveOnDrag = true;

		Add(new CGUIGumppicTiled(0x0835, 62, 88, 128, 0));

		USHORT_LIST list = GetItemsList(i);

		int size = (int)list.size();
		int maxStaticCount = g_Orion.StaticDataCount;

		int textX = 62;
		int textY = 98;

		IFOR(j, 0, size)
		{
			if (j == 6)
			{
				textX = 215;
				textY = 34;
			}

			ushort &id = list[j];

			if (id >= maxStaticCount)
				continue;

			CGUIText *text = (CGUIText*)Add(new CGUIText(0x0288, textX, textY));
			text->CreateTextureA(9, ToCamelCase(g_Orion.m_StaticData[id / 32].Tiles[id % 32].Name));

			textY += 16;
		}
	}

	Add(new CGUIPage(-1));

	m_PrevPage = (CGUIButton*)Add(new CGUIButton(ID_GCB_BUTTON_PREV, 0x08BB, 0x08BB, 0x08BB, 50, 8));
	m_PrevPage->Visible = (m_Page != 0);
	m_NextPage = (CGUIButton*)Add(new CGUIButton(ID_GCB_BUTTON_NEXT, 0x08BC, 0x08BC, 0x08BC, 321, 8));
	m_NextPage->Visible = (m_Page + 2 < m_PagesCount);
}
//----------------------------------------------------------------------------
void CGumpCombatBook::GUMP_BUTTON_EVENT_C
{
	int newPage = -1;

	if (serial == ID_GCB_BUTTON_PREV)
	{
		if (m_Page > 0)
		{
			newPage = m_Page - 2;

			if (newPage < 0)
				newPage = 0;
		}
	}
	else if (serial == ID_GCB_BUTTON_NEXT)
	{
		if (m_Page < m_PagesCount)
		{
			newPage = m_Page + 2;

			if (newPage >= m_PagesCount)
				newPage = m_PagesCount - 1;
		}
	}
	else if (serial == ID_GCB_BUTTON_MINIMIZE)
	{
		m_Minimized = true;
		m_WantUpdateContent = true;
	}
	else if (serial == ID_GCB_LOCK_MOVING)
		m_LockMoving = !m_LockMoving;
	else if (serial >= ID_GCB_ICON)
	{
		if (m_Page < m_DictionaryPagesCount) //List of spells
			newPage = m_DictionaryPagesCount + ((serial - ID_GCB_ICON) * 2);
	}

	if (newPage > -1 && !g_ClickObject.Enabled)
	{
		if (newPage % 2)
			newPage--;

		g_ClickObject.Init(g_PressedObject.LeftObject(), this);
		g_ClickObject.Timer = g_Ticks + g_MouseManager.DoubleClickDelay;
		g_ClickObject.Page = newPage;
	}
}
//----------------------------------------------------------------------------
bool CGumpCombatBook::OnLeftMouseButtonDoubleClick()
{
	bool result = false;

	if (m_Minimized)
	{
		m_Minimized = false;
		m_WantUpdateContent = true;

		result = true;
	}
	else
	{
		if (g_PressedObject.LeftSerial == ID_GCB_BUTTON_PREV)
		{
			ChangePage(0);

			m_WantRedraw = true;

			result = true;
		}
		else if (g_PressedObject.LeftSerial == ID_GCB_BUTTON_NEXT)
		{
			int newPage = m_PagesCount - 1;

			if (newPage % 2)
				newPage--;

			ChangePage(newPage);

			m_WantRedraw = true;

			result = true;
		}
		else if (g_PressedObject.LeftSerial == ID_GCB_ICON_FIRST)
		{
			CGumpAbility::OnAbilityUse(0);

			m_WantUpdateContent = true;

			result = true;
		}
		else if (g_PressedObject.LeftSerial == ID_GCB_ICON_SECOND)
		{
			CGumpAbility::OnAbilityUse(1);

			m_WantUpdateContent = true;

			result = true;
		}
	}

	return result;
}
//----------------------------------------------------------------------------------
void CGumpCombatBook::DelayedClick(CRenderObject *obj)
{
	if (obj != NULL)
	{
		ChangePage(g_ClickObject.Page);
		m_WantRedraw = true;
	}
}
//----------------------------------------------------------------------------------
void CGumpCombatBook::ChangePage(int newPage)
{
	m_Page = newPage;

	m_PrevPage->Visible = (m_Page != 0);
	m_NextPage->Visible = (m_Page + 2 < m_PagesCount);

	g_Orion.PlaySoundEffect(0x0055);
}
//----------------------------------------------------------------------------------
const string CGumpCombatBook::m_AbilityName[MAX_ABILITIES_COUNT]
{
	"Armor Ignore",
	"Bleed Attack",
	"Concussion Blow",
	"Crushing Blow",
	"Disarm",
	"Dismount",
	"Double Strike",
	"Infecting",
	"Mortal Strike",
	"Moving Shot",
	"Paralyzing Blow",
	"Shadow Strike",
	"Whirlwind Attack",
	"Riding Swipe",			//CV_500a
	"Frenzied Whirlwind",
	"Block",
	"Defense Mastery",
	"Nerve Strike",
	"Talon Strike",
	"Feint",
	"Dual Wield",
	"Double Shot",
	"Armor Pierce",
	"Bladeweave",
	"Force Arrow",
	"Lightning Arrow",
	"Psychic Attack",
	"Serpent Arrow",
	"Force of Nature",
	"Infused Throw",		//CV_7000
	"Mystic Arc"
};
//----------------------------------------------------------------------------------