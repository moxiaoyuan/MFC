
// 2015N9Y21R20131105832Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "2015N9Y21R20131105832.h"
#include "2015N9Y21R20131105832Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
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


// CMy2015N9Y21R20131105832Dlg �Ի���




CMy2015N9Y21R20131105832Dlg::CMy2015N9Y21R20131105832Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy2015N9Y21R20131105832Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2015N9Y21R20131105832Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy2015N9Y21R20131105832Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_TU1, &CMy2015N9Y21R20131105832Dlg::OnBnClickedTu1)
	ON_BN_CLICKED(IDC_TU2, &CMy2015N9Y21R20131105832Dlg::OnBnClickedTu2)
	ON_BN_CLICKED(IDC_COPY, &CMy2015N9Y21R20131105832Dlg::OnBnClickedCopy)
END_MESSAGE_MAP()


// CMy2015N9Y21R20131105832Dlg ��Ϣ�������

BOOL CMy2015N9Y21R20131105832Dlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy2015N9Y21R20131105832Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy2015N9Y21R20131105832Dlg::OnPaint()
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
HCURSOR CMy2015N9Y21R20131105832Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy2015N9Y21R20131105832Dlg::OnBnClickedTu1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//IPicture *m_picture;
    //OLE_XSIZE_HIMETRIC m_width;
   // OLE_YSIZE_HIMETRIC m_height;
	BOOL m_IsShow;//����ͼƬ��Ϣ
	m_IsShow=TRUE;
    //CString m_filename("e:\\tulips.jpg");//�ļ���
	CString m_filename;
	CFileDialog Dlg(TRUE,"jpg","*.jpg", OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,   
        "JPEG�ļ�(*.jpg)|*.jpg|GIF�ļ�(*.gif)|*.gif|bmp�ļ�(*.bmp)|*.bmp|",NULL);   
    if(Dlg.DoModal()==IDOK)   
    {   
		m_filename = Dlg.GetPathName();//ȡ���ļ�·���Լ��ļ���
	}
	else//��ʧ�ܴ���
	{
		MessageBox("��ʧ��",NULL,MB_OK);
	}
	CFile m_file(m_filename,CFile::modeRead );//��ȡ�ļ�����//CPaintDC dc(this); CFile m_file("e:\\009",CFile::modeRead);
    DWORD m_filelen = m_file.GetLength(); //�ڶ��Ϸ���ռ�
    HGLOBAL m_hglobal = GlobalAlloc(GMEM_MOVEABLE,m_filelen);
    LPVOID pvdata = NULL;//�����ѿռ�,��ȡָ��ѿռ��ָ��
    pvdata = GlobalLock(m_hglobal);//���ļ����ݶ���������
    m_file.Read(pvdata,m_filelen);
    IStream*  m_stream;
    GlobalUnlock(m_hglobal);//�ڶ��д���������
    CreateStreamOnHGlobal(m_hglobal,TRUE,&m_stream);//����������ͼ��
    OleLoadPicture(m_stream,m_filelen,TRUE,IID_IPicture,(LPVOID*)&m_picture);
    m_picture->get_Width(&m_width);
    m_picture->get_Height(&m_height);    
    CDC* dc = GetDC();
	double a = 75;
    CRect rect;
    GetClientRect(rect);
	SetScrollRange(SB_VERT,0,(int)(m_height/a)-rect.Height());
    SetScrollRange(SB_HORZ,0,(int)(m_width/a)-rect.Width());
    m_picture->Render(*dc,800,10,(int)(m_width/a),(int)(m_height/a),0,m_height,m_width,-m_height,NULL);
}


void CMy2015N9Y21R20131105832Dlg::OnBnClickedTu2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BOOL m_IsShow;//����ͼƬ��Ϣ
	m_IsShow=TRUE;
	CString m_filename;
	CFileDialog Dlg(TRUE,"jpg","*.jpg", OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,   
        "JPEG�ļ�(*.jpg)|*.jpg|GIF�ļ�(*.gif)|*.gif|bmp�ļ�(*.bmp)|*.bmp|",NULL);   
    if(Dlg.DoModal()==IDOK)   
    {   
		m_filename = Dlg.GetPathName();//ȡ���ļ�·���Լ��ļ���
	}
	else//��ʧ�ܴ���
	{
		MessageBox("��ʧ��",NULL,MB_OK);
	}
	CFile m_file(m_filename,CFile::modeRead );//��ȡ�ļ�����//CPaintDC dc(this); CFile m_file("e:\\009",CFile::modeRead);
    DWORD m_filelen = m_file.GetLength(); //�ڶ��Ϸ���ռ�
    HGLOBAL m_hglobal = GlobalAlloc(GMEM_MOVEABLE,m_filelen);
    LPVOID pvdata = NULL;//�����ѿռ�,��ȡָ��ѿռ��ָ��
    pvdata = GlobalLock(m_hglobal);//���ļ����ݶ���������
    m_file.Read(pvdata,m_filelen);
    IStream*  m_stream;
    GlobalUnlock(m_hglobal);//�ڶ��д���������
    CreateStreamOnHGlobal(m_hglobal,TRUE,&m_stream);//����������ͼ��
    OleLoadPicture(m_stream,m_filelen,TRUE,IID_IPicture,(LPVOID*)&m_picture2);
    m_picture2->get_Width(&m_width2);
    m_picture2->get_Height(&m_height2);    
    CDC* dc = GetDC();
	double b = 75;
    CRect rect;
    GetClientRect(rect);
    SetScrollRange(SB_VERT,0,(int)(m_height2/b)-rect.Height());
    SetScrollRange(SB_HORZ,0,(int)(m_width2/b)-rect.Width());
    m_picture2->Render(*dc,440,10,(int)(m_width2/b),(int)(m_height2/b),0,m_height2,m_width2,-m_height2,NULL);
}


void CMy2015N9Y21R20131105832Dlg::OnBnClickedCopy()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDC* dc = GetDC();
	BOOL m_IsShow;
	m_IsShow=TRUE;
    CRect rect;
	double c = 75;
    GetClientRect(rect);
	SetScrollRange(SB_VERT,0,(int)(m_height2/c)-rect.Height());
    SetScrollRange(SB_HORZ,0,(int)(m_width2/c)-rect.Width());
    m_picture2->Render(*dc,10,10,(int)(m_width2/(c*2)),(int)(m_height2/c),0,m_height2,m_width2/2,-m_height2,NULL);
    SetScrollRange(SB_VERT,0,(int)(m_height/c)-rect.Height());
    SetScrollRange(SB_HORZ,0,(int)(m_width/c)-rect.Width());
    m_picture->Render(*dc,190,10,(int)(m_width/(c*2)),(int)(m_height/c),0,m_height,m_width/2,-m_height,NULL);
}
