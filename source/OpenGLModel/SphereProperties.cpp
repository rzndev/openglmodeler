// SphereProperties.cpp : implementation file
//

#include "stdafx.h"
#include "OpenGLModel.h"
#include "SphereProperties.h"
#include "afxdialogex.h"


// CSphereProperties dialog

IMPLEMENT_DYNAMIC(CSphereProperties, CDialog)

CSphereProperties::CSphereProperties(CWnd* pParent /*=NULL*/)
	: CDialog(CSphereProperties::IDD, pParent)
	, m_name(_T("Объект"))
	, m_x(0)
	, m_y(0)
	, m_z(0)
	, m_r(0.5)
	, m_slices(20)
	, m_stacks(20)
	, m_color(0)
{

}

CSphereProperties::~CSphereProperties()
{
}

void CSphereProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_X, m_x);
	DDX_Text(pDX, IDC_EDIT_Y, m_y);
	DDX_Text(pDX, IDC_EDIT_Z, m_z);
	DDX_Text(pDX, IDC_EDIT_R, m_r);
	DDX_Text(pDX, IDC_EDIT_SLICES, m_slices);
	DDX_Text(pDX, IDC_EDIT_STACK, m_stacks);
}


BEGIN_MESSAGE_MAP(CSphereProperties, CDialog)
	ON_BN_CLICKED(IDOK, &CSphereProperties::OnBnClickedOk)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_COLOR, &CSphereProperties::OnBnClickedButtonColor)
END_MESSAGE_MAP()


// CSphereProperties message handlers








void CSphereProperties::OnBnClickedOk()
{
	UpdateData();
	CDialog::OnOK();
}


BOOL CSphereProperties::OnInitDialog()
{
	CDialog::OnInitDialog();

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


// Установить цвет
void CSphereProperties::SetColor(DWORD color)
{
	m_color = color;
	Invalidate(FALSE); // выполняем перерисовку окна диалога
}


void CSphereProperties::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages
	CRect rect;
	CWnd* wnd = GetDlgItem(IDC_STATIC_COLOR); // получаем элемент управления, в котором будем отображать цвет
	wnd->GetWindowRect(&rect);                 // получаем экранные координаты элемента
	ScreenToClient(&rect);                     // преобразуем в координаты относительно левого верхнего окна диалога
	CPen pen(PS_SOLID,1,RGB(0,0,0));
	CPen *oldPen = dc.SelectObject(&pen);
	CBrush brush(m_color);
	CBrush* oldBrush = dc.SelectObject(&brush);
	dc.Rectangle(rect);                       // отображаем цвет в диалоге
	dc.SelectObject(oldPen);
	dc.SelectObject(oldBrush);
}


void CSphereProperties::OnBnClickedButtonColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;
	m_color = (DWORD)dlg.GetColor(); // Если пользователь изменил цвет, устанавливаем в качестве активного его
	Invalidate(FALSE); // обновляем форму диалогового окна для отображения цвета
}
