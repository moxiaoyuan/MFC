
// ImageDlg.h : ͷ�ļ�
//

#pragma once


// CImageDlg �Ի���
class CImageDlg : public CDialogEx
{
// ����
public:
	CImageDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_IMAGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
