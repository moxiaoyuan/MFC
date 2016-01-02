
// ImageDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Image.h"
#include "ImageDlg.h"
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


// CImageDlg �Ի���




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


// CImageDlg ��Ϣ�������

BOOL CImageDlg::OnInitDialog()
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CImageDlg::OnPaint()
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
HCURSOR CImageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CImageDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	
	
	

	IPicture *m_picture;
    OLE_XSIZE_HIMETRIC m_width;
    OLE_YSIZE_HIMETRIC m_height;
	BOOL m_IsShow;//����ͼƬ��Ϣ

    CString m_filename("f:\\tulips.jpg");//�ļ���
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������



	IPicture *m_picture;
    OLE_XSIZE_HIMETRIC m_width;
    OLE_YSIZE_HIMETRIC m_height;
	BOOL m_IsShow;//����ͼƬ��Ϣ

    CString m_filename("f:\\koala.jpg");//�ļ���
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

	m_IsShow=TRUE;
    CRect rect;
    GetClientRect(rect);
    SetScrollRange(SB_VERT,0,(int)(m_height/50)-rect.Height());
    SetScrollRange(SB_HORZ,0,(int)(m_width/50)-rect.Width());

    m_picture->Render(*dc,1,20,(int)(m_width/50),(int)(m_height/54),0,m_height,m_width,-m_height,NULL);
	
	}
