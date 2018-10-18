
// TestPLCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestPLC.h"
#include "TestPLCDlg.h"
#include "SocketManager.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

SockAddrIn m_SockPeer;

CSocketManager m_SocketManager;
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestPLCDlg �Ի���



CTestPLCDlg::CTestPLCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTPLC_DIALOG, pParent)
	, m_strShake(L"46494E530000000C000000000000000000000002")
	, m_radiobtngroup(0)
	, m_port(_T("1000"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	output = nullptr;
}

void CTestPLCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strShake);
	DDX_Control(pDX, IDC_EDIT2, m_msglist);
	DDX_Radio(pDX, IDC_RADIO1, m_radiobtngroup);
	DDX_Control(pDX, IDC_IPADDRESS1, m_add);
	DDX_Text(pDX, IDC_EDIT3, m_port);
}

BEGIN_MESSAGE_MAP(CTestPLCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SEND, &CTestPLCDlg::OnBnClickedBtnSend)
	ON_BN_CLICKED(IDC_RADIO1, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO4, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO5, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO6, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO7, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO8, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO9, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO10, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO11, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO12, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO13, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO14, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO15, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO16, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO17, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO18, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO19, &CTestPLCDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO20, &CTestPLCDlg::OnBnClickedRadio1)

	ON_BN_CLICKED(IDC_BUTTON1, &CTestPLCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestPLCDlg::OnBnClickedButton2)

END_MESSAGE_MAP()


// CTestPLCDlg ��Ϣ�������

BOOL CTestPLCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_SocketManager.StopComm();
	//Sleep(100);
//	Connect();

	m_add.SetAddress(192, 168, 250, 1);

	m_SocketManager.SetMessageWindow(&m_msglist);

	m_SocketManager.SetServerState(false);	// run as client

	m_SocketManager.SetSmartAddressing(false);	// always send to server

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestPLCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		if ((nID & 0xFFF0) == SC_CLOSE)
		{
			
			m_SocketManager.StopComm();
			if (m_SocketManager.IsOpen())
				MessageBox(L"socket still open");
			
		}
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestPLCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTestPLCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/************************************************************************/
/* ���ӷ����
/************************************************************************/
/*void CTestPLCDlg::Connect()
{
	const int SOCK_TCP = 0;

	CString m_strPort = L"60000";

	int m_nSockType = SOCK_TCP;

	CString strLocal=L"192.168.1.20";

	bool bSuccess = FALSE;

	if (m_nSockType != SOCK_TCP)
	{
		return;
	}
	else
	{
		bSuccess = m_SocketManager.ConnectTo(strLocal, m_strPort, AF_INET, SOCK_STREAM); // TCP
	}

	if (bSuccess && m_SocketManager.WatchComm())
	{

		if (m_nSockType != SOCK_TCP)
		{
			return;
		}
		else
		{
			m_SocketManager.GetPeerName(m_SockPeer);
		}
	}
	else
	{
		AfxMessageBox(L"�������ʧ�ܣ������ر�");
		SendMessage(WM_CLOSE);
	}
	
}*/


/************************************************************************/
/*����: ����ָ��
/************************************************************************/
void CTestPLCDlg::Send(std::string str)
{
	    char *p = nullptr;
		p = hextostr(str);

		int nLen = str.length() / 2;
		
		if (nLen > 0)
		{
			m_SocketManager.WriteComm((unsigned char*)p, nLen , INFINITE);
		}
	
		delete[]output;
}


char* CTestPLCDlg::hextostr(const std::string& hexStr)
{
	size_t len = hexStr.length();
	int k = 0;
	if (len & 1)
		return NULL;

	output = new char[(len / 2) + 1];

	for (size_t i = 0; i < len; i += 2)
	{
		output[k++] = (((hexStr[i] >= 'A') ? (hexStr[i] - 'A' + 10) : (hexStr[i] - '0')) << 4) |
			(((hexStr[i + 1] >= 'A') ? (hexStr[i + 1] - 'A' + 10) : (hexStr[i + 1] - '0')));
	}
	output[k] = '\0';

	return output;
}

void CTestPLCDlg::OnBnClickedBtnSend()
{
	UpdateData(TRUE);

	Send((LPCSTR)(CStringA)m_strShake);

}

void CTestPLCDlg::OnBnClickedRadio1()
{
	UpdateData(TRUE);

	std::string hexStr;

	switch (m_radiobtngroup)
	{
	case 0:
		hexStr = "EE011000"; //C����ī��Һλ
		Send(hexStr);
		break;
	case 1:
		hexStr = "EE010000";
		Send(hexStr);
		break;
	case 2:
		hexStr = "EE011001";  //M����ī��Һλ
		Send(hexStr);
		break;
	case 3:
		hexStr = "EE010001";
		Send(hexStr);
		break;
	case 4:
		hexStr = "EE011002";  //Y����ī��Һλ
		Send(hexStr);
		break;
	case 5:
		hexStr = "EE010002";
		Send(hexStr);
		break;
	case 6:
		hexStr = "EE011003";  //K����ī��Һλ
		Send(hexStr);
		break;
	case 7:
		hexStr = "EE010003";
		Send(hexStr);
		break;
	case 8:
		hexStr = "EE011004"; //��ӡ״̬�ź�
		Send(hexStr);
		break;
	case 9:
		hexStr = "EE010004";
		Send(hexStr);
		break;
	case 10:
		hexStr = "EE011005"; //�ر���λ�����ź�
		Send(hexStr);
		break;
	case 11:
		hexStr = "EE010005";
		Send(hexStr);
		break;
	case 12:
		hexStr = "EE011006"; //��ʪ״̬�ź�
		Send(hexStr);
		break;
	case 13:
		hexStr = "EE010006";
		Send(hexStr);
		break;
	case 14:
		hexStr = "EE011007"; //ѹ�������ź�
		Send(hexStr);
		break;
	case 15:
		hexStr = "EE010007";
		Send(hexStr);
		break;
	case 16:
		hexStr = "EE011008"; //��ײ�����ź�
		Send(hexStr);
		break;
	case 17:
		hexStr = "EE010008";
		Send(hexStr);
		break;
	case 18:
		hexStr = "EE011009"; //ȱ���ź�
		Send(hexStr);
		break;
	case 19:
		hexStr = "EE010009";
		Send(hexStr);
		break;
	default:
		break;
	}

}

void CTestPLCDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	double DD = 5.6935;
	TCHAR SF = DD;


	UpdateData(TRUE);

	DWORD dwIP;

	IN_ADDR ia;

	CString strIP;

	m_add.GetAddress(dwIP);

	ia.S_un.S_addr = htonl(dwIP);

	strIP = inet_ntoa(ia);

	const int SOCK_TCP = 0;

	int m_nSockType = SOCK_TCP;

	bool bSuccess = FALSE;

	if (m_nSockType != SOCK_TCP)
	{
		return;
	}
	else
	{
		//strPort.Format(L"%d", m_iPort);

		bSuccess = m_SocketManager.ConnectTo(strIP, m_port, AF_INET, SOCK_STREAM); // TCP
	}

	if (bSuccess && m_SocketManager.WatchComm())
	{
		if (m_nSockType != SOCK_TCP)
		{
			return;
		}
		else
		{
			m_SocketManager.GetPeerName(m_SockPeer);
		}
	}
	else
	{
		AfxMessageBox(L"PLC����ʧ��");

		SendMessage(WM_CLOSE);
	}
	UpdateData(FALSE);

}


void CTestPLCDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_SocketManager.StopComm();
	if (m_SocketManager.IsOpen())
		MessageBox(L"socket still open");

	
}


