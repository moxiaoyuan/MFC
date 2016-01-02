
// 2015N9Y21R20131105832Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "2015N9Y21R20131105832.h"
#include "2015N9Y21R20131105832Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMy2015N9Y21R20131105832Dlg 对话框




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


// CMy2015N9Y21R20131105832Dlg 消息处理程序

BOOL CMy2015N9Y21R20131105832Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy2015N9Y21R20131105832Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy2015N9Y21R20131105832Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy2015N9Y21R20131105832Dlg::OnBnClickedTu1()
{
	// TODO: 在此添加控件通知处理程序代码
	//IPicture *m_picture;
    //OLE_XSIZE_HIMETRIC m_width;
   // OLE_YSIZE_HIMETRIC m_height;
	BOOL m_IsShow;//背景图片信息
	m_IsShow=TRUE;
    //CString m_filename("e:\\tulips.jpg");//文件名
	CString m_filename;
	CFileDialog Dlg(TRUE,"jpg","*.jpg", OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,   
        "JPEG文件(*.jpg)|*.jpg|GIF文件(*.gif)|*.gif|bmp文件(*.bmp)|*.bmp|",NULL);   
    if(Dlg.DoModal()==IDOK)   
    {   
		m_filename = Dlg.GetPathName();//取得文件路径以及文件名
	}
	else//打开失败处理
	{
		MessageBox("打开失败",NULL,MB_OK);
	}
	CFile m_file(m_filename,CFile::modeRead );//获取文件长度//CPaintDC dc(this); CFile m_file("e:\\009",CFile::modeRead);
    DWORD m_filelen = m_file.GetLength(); //在堆上分配空间
    HGLOBAL m_hglobal = GlobalAlloc(GMEM_MOVEABLE,m_filelen);
    LPVOID pvdata = NULL;//锁定堆空间,获取指向堆空间的指针
    pvdata = GlobalLock(m_hglobal);//将文件数据读区到堆中
    m_file.Read(pvdata,m_filelen);
    IStream*  m_stream;
    GlobalUnlock(m_hglobal);//在堆中创建流对象
    CreateStreamOnHGlobal(m_hglobal,TRUE,&m_stream);//利用流加载图像
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
	// TODO: 在此添加控件通知处理程序代码
	BOOL m_IsShow;//背景图片信息
	m_IsShow=TRUE;
	CString m_filename;
	CFileDialog Dlg(TRUE,"jpg","*.jpg", OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,   
        "JPEG文件(*.jpg)|*.jpg|GIF文件(*.gif)|*.gif|bmp文件(*.bmp)|*.bmp|",NULL);   
    if(Dlg.DoModal()==IDOK)   
    {   
		m_filename = Dlg.GetPathName();//取得文件路径以及文件名
	}
	else//打开失败处理
	{
		MessageBox("打开失败",NULL,MB_OK);
	}
	CFile m_file(m_filename,CFile::modeRead );//获取文件长度//CPaintDC dc(this); CFile m_file("e:\\009",CFile::modeRead);
    DWORD m_filelen = m_file.GetLength(); //在堆上分配空间
    HGLOBAL m_hglobal = GlobalAlloc(GMEM_MOVEABLE,m_filelen);
    LPVOID pvdata = NULL;//锁定堆空间,获取指向堆空间的指针
    pvdata = GlobalLock(m_hglobal);//将文件数据读区到堆中
    m_file.Read(pvdata,m_filelen);
    IStream*  m_stream;
    GlobalUnlock(m_hglobal);//在堆中创建流对象
    CreateStreamOnHGlobal(m_hglobal,TRUE,&m_stream);//利用流加载图像
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
	// TODO: 在此添加控件通知处理程序代码
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
