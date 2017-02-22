#pragma once
#include "afxwin.h"


// Cuadro de diálogo de CHistory

class CHistory : public CDialogEx
{
	DECLARE_DYNAMIC(CHistory)

public:
	CHistory(CWnd* pParent = NULL);   // Constructor estándar
	virtual ~CHistory();

// Datos del cuadro de diálogo
	enum { IDD = IDD_History };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
  CListBox m_list;
  std::vector<std::pair<CString, CString>> m_history2;
  afx_msg void OnPaint();
  bool m_flag;
};
