
// DummyChatDlg.h: archivo de encabezado
//

#pragma once
#include <vector>
#include "afxwin.h"
#include "History.h"

// Cuadro de diálogo de CDummyChatDlg
class CDummyChatDlg : public CDialogEx
{
// Construcción
public:
	CDummyChatDlg(CWnd* pParent = NULL);	// Constructor estándar

// Datos del cuadro de diálogo
	enum { IDD = IDD_DUMMYCHAT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnBnClickedbnsend();
  CString ChooseAnswer();
  CString m_answer;
  CString m_question;
  CString m_through;
  std::vector<std::pair<CString, CString>> m_history;
  CStatic m_flowey;
private:
  CBitmap m_angryImg, m_happyImg, m_sadImg, m_neutralImg;
public:
  afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
  afx_msg void OnBnClickedbnhistory();
  CHistory m_historyDialog;
};
