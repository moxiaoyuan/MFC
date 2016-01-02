
// ImageDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Image.h"
#include "ImageDlg.h"
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


// CImageDlg 对话框




CImageDlg::CImageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImageDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CImageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CImageDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CImageDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CImageDlg 消息处理程序

BOOL CImageDlg::OnInitDialog()
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

void CImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CImageDlg::OnPaint()
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
HCURSOR CImageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CImageDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	
	
	

	IPicture *m_picture;
    OLE_XSIZE_HIMETRIC m_width;
    OLE_YSIZE_HIMETRIC m_height;
	BOOL m_IsShow;//背景图片信息

    CString m_filename("f:\\tulips.jpg");//文件名
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

	m_IsShow=TRUE;
    CRect rect;
    GetClientRect(rect);
   // SetScrollRange(SB_VERT,0,(int)(m_height/26.45)-rect.Height());
   // SetScrollRange(SB_HORZ,0,(int)(m_width/26.45)-rect.Width());
	SetScrollRange(SB_VERT,0,(int)(m_height/50)-rect.Height());
    SetScrollRange(SB_HORZ,0,(int)(m_width/50)-rect.Width());
    m_picture->Render(*dc,500,20,(int)(m_width/50),(int)(m_height/54),0,m_height,m_width,-m_height,NULL);
	//m_picture->Render(*dc,1,20,(int)(m_width/26.45),(int)(m_height/30),0,m_height,m_width,-m_height,NULL);
	
}


bool CImageDlg::ImageGif(CString strPath, int x, int y)
{
	return false;
}


void CImageDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码



	IPicture *m_picture;
    OLE_XSIZE_HIMETRIC m_width;
    OLE_YSIZE_HIMETRIC m_height;
	BOOL m_IsShow;//背景图片信息

    CString m_filename("f:\\koala.jpg");//文件名
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

	m_IsShow=TRUE;
    CRect rect;
    GetClientRect(rect);
    SetScrollRange(SB_VERT,0,(int)(m_height/50)-rect.Height());
    SetScrollRange(SB_HORZ,0,(int)(m_width/50)-rect.Width());

    m_picture->Render(*dc,1,20,(int)(m_width/50),(int)(m_height/54),0,m_height,m_width,-m_height,NULL);
	
	}
