// History.cpp: archivo de implementación
//

#include "stdafx.h"
#include "DummyChat.h"
#include "History.h"
#include "afxdialogex.h"


// Cuadro de diálogo de CHistory

IMPLEMENT_DYNAMIC(CHistory, CDialogEx)

CHistory::CHistory(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHistory::IDD, pParent)
{
  m_flag = false;
}

CHistory::~CHistory()
{
}

void CHistory::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Control(pDX, lsHistory, m_list);
}


BEGIN_MESSAGE_MAP(CHistory, CDialogEx)
  ON_WM_PAINT()
END_MESSAGE_MAP()


// Controladores de mensajes de CHistory


void CHistory::OnPaint()
{
 for(size_t ii = 0; ii < m_history2.size() && !m_flag; ii++){
    m_list.AddString(m_history2.at(ii).first);
    m_list.AddString(m_history2.at(ii).second);
  }
 m_flag = true;
}
