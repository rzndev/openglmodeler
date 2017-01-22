// BoxProperties.cpp: файл реализации
//

#include "stdafx.h"
#include "OpenGLModel.h"
#include "BoxProperties.h"
#include "afxdialogex.h"


// диалоговое окно CBoxProperties

IMPLEMENT_DYNAMIC(CBoxProperties, CDialog)

CBoxProperties::CBoxProperties(CWnd* pParent /*=NULL*/)
	: CDialog(CBoxProperties::IDD, pParent)
	, m_x(0)
	, m_y(0)
	, m_z(0)
	, m_rx(0)
	, m_ry(0)
	, m_rz(0)
	, m_a(0.5)
	, m_b(0.5)
	, m_c(0.5)
	, m_name(_T("Объект"))
	, m_title(_T(""))
	, m_color(0)
{

}

CBoxProperties::~CBoxProperties()
{
}

void CBoxProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_X, m_x);
	DDX_Text(pDX, IDC_EDIT_Y, m_y);
	DDX_Text(pDX, IDC_EDIT_Z, m_z);
	DDX_Text(pDX, IDC_EDIT_RX, m_rx);
	DDX_Text(pDX, IDC_EDIT_RY, m_ry);
	DDX_Text(pDX, IDC_EDIT_RZ, m_rz);
	DDX_Text(pDX, IDC_EDIT_A, m_a);
	DDX_Text(pDX, IDC_EDIT_B, m_b);
	DDX_Text(pDX, IDC_EDIT_C, m_c);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
}


BEGIN_MESSAGE_MAP(CBoxProperties, CDialog)
	ON_BN_CLICKED(IDOK, &CBoxProperties::OnBnClickedOk)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_COLOR, &CBoxProperties::OnBnClickedButtonColor)
END_MESSAGE_MAP()


// обработчики сообщений CBoxProperties


void CBoxProperties::OnBnClickedOk()
{
	UpdateData();
	CDialog::OnOK();
}


BOOL CBoxProperties::OnInitDialog()
{
	CDialog::OnInitDialog();

	UpdateData(FALSE); // Отображаем значения параметров в соответствующих элементах управления
	if (!m_title.IsEmpty()) SetWindowText(m_title);
	return TRUE;  // return TRUE unless you set the focus to a control
	// Исключение: страница свойств OCX должна возвращать значение FALSE
}


// Установить заголовок диалогового окна
void CBoxProperties::SetTtitle(CString tittle)
{
	m_title = tittle;
}


// Установить цвет
void CBoxProperties::SetColor(DWORD color)
{
	m_color = color;
	Invalidate(FALSE);
}


void CBoxProperties::OnPaint()
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


void CBoxProperties::OnBnClickedButtonColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;
	m_color = (DWORD)dlg.GetColor(); // Если пользователь изменил цвет, устанавливаем в качестве активного его
	Invalidate(FALSE); // обновляем форму диалогового окна для отображения цвета
}
