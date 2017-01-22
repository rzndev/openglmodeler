
// OpenGLModel.cpp : Определяет поведение классов для приложения.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "OpenGLModel.h"
#include "MainFrm.h"

#include "OpenGLModelDoc.h"
#include "UserGui.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpenGLModelApp

BEGIN_MESSAGE_MAP(COpenGLModelApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &COpenGLModelApp::OnAppAbout)
	// Стандартные команды по работе с файлами документов
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
END_MESSAGE_MAP()


// создание COpenGLModelApp

COpenGLModelApp::COpenGLModelApp()
{
	m_bHiColorIcons = TRUE;

	// поддержка диспетчера перезагрузки
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// Если приложение построено с поддержкой среды Common Language Runtime (/clr):
	//     1) Этот дополнительный параметр требуется для правильной поддержки работы диспетчера перезагрузки.
	//     2) В своем проекте для построения необходимо добавить ссылку на System.Windows.Forms.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: замените ниже строку идентификатора приложения строкой уникального идентификатора; рекомендуемый
	// формат для строки: ИмяКомпании.ИмяПродукта.СубПродукт.СведенияОВерсии
	SetAppID(_T("OpenGLModel.AppID.NoVersion"));

	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}

// Единственный объект COpenGLModelApp

COpenGLModelApp theApp;


// инициализация COpenGLModelApp

BOOL COpenGLModelApp::InitInstance()
{
	// InitCommonControlsEx() требуются для Windows XP, если манифест
	// приложения использует ComCtl32.dll версии 6 или более поздней версии для включения
	// стилей отображения. В противном случае будет возникать сбой при создании любого окна.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Выберите этот параметр для включения всех общих классов управления, которые необходимо использовать
	// в вашем приложении.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// Инициализация библиотек OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// Для использования элемента управления RichEdit требуется метод AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// Стандартная инициализация
	// Если эти возможности не используются и необходимо уменьшить размер
	// конечного исполняемого файла, необходимо удалить из следующего
	// конкретные процедуры инициализации, которые не требуются
	// Измените раздел реестра, в котором хранятся параметры
	// TODO: следует изменить эту строку на что-нибудь подходящее,
	// например на название организации
	SetRegistryKey(_T("Локальные приложения, созданные с помощью мастера приложений"));
	LoadStdProfileSettings(4);  // Загрузите стандартные параметры INI-файла (включая MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// регистрируем класс окна, в котором осуществляется вывод OpenGL
	

	WNDCLASS wndcls;

	memset(&wndcls, 0, sizeof(WNDCLASS));   // start with NULL defaults

	wndcls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;

	//you can specify your own window procedure
	wndcls.lpfnWndProc = ::DefWindowProc; 
	wndcls.hInstance = AfxGetInstanceHandle();
	wndcls.hIcon = NULL;//LoadIcon(wndcls.hInstance, MAKEINTRESOURCE(IDI_MYICON));
	wndcls.hCursor = ::LoadCursor(wndcls.hInstance, MAKEINTRESOURCE(IDC_ARROW));
	wndcls.hbrBackground = NULL;//(HBRUSH)(COLOR_WINDOW + 1);
	wndcls.lpszMenuName = NULL;

	// Specify your own class name for using FindWindow later
	wndcls.lpszClassName = OpenGLWndClassName;

	// Register the new class and trace if it fails
	if(!AfxRegisterClass(&wndcls))
	{
	   TRACE("Class Registration Failed\n");
	}
	// Зарегистрируйте шаблоны документов приложения. Шаблоны документов
	//  выступают в роли посредника между документами, окнами рамок и представлениями
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(COpenGLModelDoc),
		RUNTIME_CLASS(CMainFrame),       // основное окно рамки SDI
		RUNTIME_CLASS(CUserGui));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Синтаксический разбор командной строки на стандартные команды оболочки, DDE, открытие файлов
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Включить открытие выполнения DDE
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);


	// Команды диспетчеризации, указанные в командной строке. Значение FALSE будет возвращено, если
	// приложение было запущено с параметром /RegServer, /Register, /Unregserver или /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Одно и только одно окно было инициализировано, поэтому отобразите и обновите его
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// вызов DragAcceptFiles только при наличии суффикса
	//  В приложении SDI это должно произойти после ProcessShellCommand
	// Включить открытие перетаскивания
	m_pMainWnd->DragAcceptFiles();
	return TRUE;
}

int COpenGLModelApp::ExitInstance()
{
	//TODO: обработайте дополнительные ресурсы, которые могли быть добавлены
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// обработчики сообщений COpenGLModelApp


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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

// Команда приложения для запуска диалога
void COpenGLModelApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// COpenGLModelApp настройка методов загрузки и сохранения

void COpenGLModelApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void COpenGLModelApp::LoadCustomState()
{
}

void COpenGLModelApp::SaveCustomState()
{
}

// обработчики сообщений COpenGLModelApp



