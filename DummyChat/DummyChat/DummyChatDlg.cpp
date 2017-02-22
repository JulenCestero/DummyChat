
// DummyChatDlg.cpp: includes
//

#include "stdafx.h"
#include "DummyChat.h"
#include "DummyChatDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// About dialog box
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog box data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV compatibility

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
//  afx_msg void OnMenuHistory();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDummyChatDlg dialog box



CDummyChatDlg::CDummyChatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDummyChatDlg::IDD, pParent)
  , m_question(_T(""))
  , m_answer(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDummyChatDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Text(pDX, txbxQuestion, m_question);
  DDX_Text(pDX, txbxQuestion2, m_through);
  DDX_Text(pDX, txbxAnswer, m_answer);
  DDX_Control(pDX, imFlowey, m_flowey);
}

BEGIN_MESSAGE_MAP(CDummyChatDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
  ON_BN_CLICKED(bnSend, &CDummyChatDlg::OnBnClickedbnsend)
  ON_WM_CTLCOLOR()
  ON_BN_CLICKED(bnHistory, &CDummyChatDlg::OnBnClickedbnhistory)
END_MESSAGE_MAP()


// CDummyChatDlg messages

BOOL CDummyChatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
  // Additional initializations:
  // Icon initialization
  HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
  SetIcon(hIcon, FALSE);
  // First flowey image initialization
  m_angryImg.LoadBitmap(IDB_BITMAP1);
  m_happyImg.LoadBitmap(IDB_BITMAP3);
  m_sadImg.LoadBitmap(IDB_BITMAP4);
  m_neutralImg.LoadBitmap(IDB_BITMAP2);
	return TRUE; 
}

void CDummyChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Code executed when the dialog is minimized or maximized
void CDummyChatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CDummyChatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Function to choose the answer to user questions
CString CDummyChatDlg::ChooseAnswer()
{
  if(m_question.Find("?") != -1){
    if(m_question.Find("What") != -1 || m_question.Find("what") != -1){
      m_flowey.SetBitmap(m_sadImg);
      return "A. Everything... and everyone...";
    }
    else if (m_question.Find("How old") != -1 || m_question.Find("how old") != -1){
      m_flowey.SetBitmap(m_sadImg);
      return "A. Endless... timeless...";
    }
    else if (m_question.Find("How") != -1 || m_question.Find("how") != -1){
      m_flowey.SetBitmap(m_angryImg);
      return "A. In the evilest way possible";
    }
    else if (m_question.Find("Who") != -1 || m_question.Find("who") != -1){
      m_flowey.SetBitmap(m_happyImg);
      return "A. You... or myself, depending on the coodrinates' origin";
    }
    else if (m_question.Find("Where") != -1 || m_question.Find("where") != -1){
      m_flowey.SetBitmap(m_sadImg);
      return "A. In the middle of nowhere";
    }
    else if (m_question.Find("When") != -1 || m_question.Find("when") != -1){
      m_flowey.SetBitmap(m_happyImg);
      return "A. Anytime ^^";
    }
    else if (m_question.Find("Why") != -1 || m_question.Find("why") != -1){
      m_flowey.SetBitmap(m_angryImg);
      return "A. Because I hate you and everyone else";
    }
    else if (m_question.Find("Which") != -1 || m_question.Find("which") != -1){
      m_flowey.SetBitmap(m_happyImg);
      return "A. The one you prefer";
    }
    m_flowey.SetBitmap(m_neutralImg);
    return "A. Every question has an answer if you believe in the power of love :)";
  }
  else{
    if(m_question.Find("Yes") != -1 || m_question.Find("yes") != -1){
      m_flowey.SetBitmap(m_happyImg);
      return "A. Or maybe not...";
    }
    else if(m_question.Find("No") != -1 || m_question.Find("no") != -1){
      m_flowey.SetBitmap(m_happyImg);
      return "A. Or maybe yes...";
    }
    else if(m_question.Find("Hello") != -1 || m_question.Find("hello") != -1){
      m_flowey.SetBitmap(m_happyImg);
      return "A. Welcome, my master! Feed me with questions please :)";
    }
    else if(m_question.Find("Hallo") != -1 || m_question.Find("hallo") != -1){
      m_flowey.SetBitmap(m_happyImg);
      return "A. Willkommen, mein Herr! Sprechen Sie aber bitte Englisch, denn meine Fähigkeiten sind begrenzt :(";
    }
    else if(m_question.Find("Bye") != -1 || m_question.Find("bye") != -1){
      m_flowey.SetBitmap(m_sadImg);
      return "A. Don't leave me please...";
    }
    else if(m_question.Compare("") == 0){
      m_flowey.SetBitmap(m_angryImg);
      return "A. Waiting for youu~";
    }
    m_flowey.SetBitmap(m_happyImg);
    return "A. Really?";
  }
}

// Function to interact user-computer
void CDummyChatDlg::OnBnClickedbnsend()
{
  UpdateData(1);
  m_answer = ChooseAnswer();
  m_history.push_back(std::make_pair("Q. " + m_question, m_answer));
  m_through = "Q. " + m_question;
  m_question = "";
  UpdateData(0);
}


HBRUSH CDummyChatDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
  // For future implementations: apply style to the app
  return 0;
}


void CDummyChatDlg::OnBnClickedbnhistory()
{
  m_historyDialog.m_history2 = m_history;
  m_historyDialog.DoModal();
  m_historyDialog.m_flag = false;
}
