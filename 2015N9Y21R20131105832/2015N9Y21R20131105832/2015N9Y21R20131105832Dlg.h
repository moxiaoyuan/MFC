
// 2015N9Y21R20131105832Dlg.h : ͷ�ļ�
//

#pragma once


// CMy2015N9Y21R20131105832Dlg �Ի���
class CMy2015N9Y21R20131105832Dlg : public CDialogEx
{
// ����
public:
	CMy2015N9Y21R20131105832Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY2015N9Y21R20131105832_DIALOG };

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
	afx_msg void OnBnClickedTu1();
	afx_msg void OnBnClickedTu2();
	afx_msg void OnBnClickedCopy();
};
