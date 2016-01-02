
// ImageDlg.h : 头文件
//

#pragma once


// CImageDlg 对话框
class CImageDlg : public CDialogEx
{
// 构造
public:
	CImageDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_IMAGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	IPicture *m_picture2;
    OLE_XSIZE_HIMETRIC m_width2;
    OLE_YSIZE_HIMETRIC m_height2;
	IPicture *m_picture;
    OLE_XSIZE_HIMETRIC m_width;
    OLE_YSIZE_HIMETRIC m_height;
public:
	afx_msg void OnBnClickedButton1();
	bool ImageGif(CString strPath, int x, int y);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCopy();
};
