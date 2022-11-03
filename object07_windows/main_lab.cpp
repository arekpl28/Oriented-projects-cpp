/******************************************************************
 Grafika komputerowa, �rodowisko MS Windows - program  przyk�adowy  m litere C
 *****************************************************************/
#include <windows.h>
#include <gdiplus.h>
using namespace Gdiplus;

// deklaracja funkcji obslugi okna
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// funkcja Main - dla Windows
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
  MSG meldunek;         // innymi slowy "komunikat"
  WNDCLASS nasza_klasa; // klasa g��wnego okna aplikacji
  HWND okno;
  static char nazwa_klasy[] = "Podstawowa";

  GdiplusStartupInput gdiplusParametry; // parametry GDI+; domy�lny konstruktor wype�nia struktur� odpowiednimi warto�ciami
  ULONG_PTR gdiplusToken;               // tzw. token GDI+; warto�� uzyskiwana przy inicjowaniu i przekazywana do funkcji GdiplusShutdown

  // Inicjujemy GDI+.
  GdiplusStartup(&gdiplusToken, &gdiplusParametry, NULL);

  // Definiujemy klase g��wnego okna aplikacji
  // Okreslamy tu wlasciwosci okna, szczegoly wygladu oraz
  // adres funkcji przetwarzajacej komunikaty
  nasza_klasa.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
  nasza_klasa.lpfnWndProc = WndProc; // adres funkcji realizuj�cej przetwarzanie meldunk�w
  nasza_klasa.cbClsExtra = 0;
  nasza_klasa.cbWndExtra = 0;
  nasza_klasa.hInstance = hInstance; // identyfikator procesu przekazany przez MS Windows podczas uruchamiania programu
  nasza_klasa.hIcon = 0;
  nasza_klasa.hCursor = LoadCursor(0, IDC_ARROW);
  nasza_klasa.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
  nasza_klasa.lpszMenuName = "Menu";
  nasza_klasa.lpszClassName = nazwa_klasy;

  // teraz rejestrujemy klas� okna g��wnego
  RegisterClass(&nasza_klasa);

  /*tworzymy okno g��wne
  okno b�dzie mia�o zmienne rozmiary, listw� z tytu�em, menu systemowym
  i przyciskami do zwijania do ikony i rozwijania na ca�y ekran, po utworzeniu
  b�dzie widoczne na ekranie */
  okno = CreateWindow(nazwa_klasy, "Grafika komputerowa", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

  /* wyb�r rozmiaru i usytuowania okna pozostawiamy systemowi MS Windows */
  ShowWindow(okno, nCmdShow);

  // odswiezamy zawartosc okna
  UpdateWindow(okno);

  // G��WNA P�TLA PROGRAMU
  while (GetMessage(&meldunek, NULL, 0, 0))
  /* pobranie komunikatu z kolejki; funkcja GetMessage zwraca FALSE tylko dla
komunikatu WM_QUIT; dla wszystkich pozosta�ych komunikat�w zwraca warto�� TRUE */
  {
    TranslateMessage(&meldunek); // wst�pna obr�bka komunikatu
    DispatchMessage(&meldunek);  // przekazanie komunikatu w�a�ciwemu adresatowi (czyli funkcji obslugujacej odpowiednie okno)
  }

  GdiplusShutdown(gdiplusToken);

  return (int)meldunek.wParam;
}

/********************************************************************
FUNKCJA OKNA realizujaca przetwarzanie meldunk�w kierowanych do okna aplikacji*/
LRESULT CALLBACK WndProc(HWND okno, UINT kod_meldunku, WPARAM wParam, LPARAM lParam)
{
  HMENU mPlik, mInfo, mGlowne;

  /* PONI�SZA INSTRUKCJA DEFINIUJE REAKCJE APLIKACJI NA POSZCZEG�LNE MELDUNKI */
  switch (kod_meldunku)
  {
  case WM_CREATE: // meldunek wysy�any w momencie tworzenia okna
    mPlik = CreateMenu();
    AppendMenu(mPlik, MF_STRING, 100, "&Zapiszcz...");
    AppendMenu(mPlik, MF_SEPARATOR, 0, "");
    AppendMenu(mPlik, MF_STRING, 101, "&Koniec");
    mInfo = CreateMenu();
    AppendMenu(mInfo, MF_STRING, 200, "&Autor...");
    mGlowne = CreateMenu();
    AppendMenu(mGlowne, MF_POPUP, (UINT_PTR)mPlik, "&Plik");
    AppendMenu(mGlowne, MF_POPUP, (UINT_PTR)mInfo, "&Informacja");
    SetMenu(okno, mGlowne);
    DrawMenuBar(okno);

  case WM_COMMAND: // reakcje na wyb�r opcji z menu
    switch (wParam)
    {
    case 100:
      if (MessageBox(okno, "Zapiszcze�?", "Pisk", MB_YESNO) == IDYES)
        MessageBeep(0);
      break;
    case 101:
      DestroyWindow(okno); // wysylamy meldunek WM_DESTROY
      break;
    case 200:
      MessageBox(okno, "Imi� i nazwisko:\nNumer indeksu: ", "Autor", MB_OK);
    }
    return 0;

  case WM_LBUTTONDOWN: // reakcja na lewy przycisk myszki
  {
    int x = LOWORD(lParam);
    int y = HIWORD(lParam);

    return 0;
  }

  case WM_PAINT:
  {
    PAINTSTRUCT paint;
    HDC kontekst;

    HPEN pioro = CreatePen(PS_SOLID, 10, RGB(255, 255, 0));

    kontekst = BeginPaint(okno, &paint);

    Graphics grafika(kontekst);
    // MIEJSCE NA KOD GDI
    HBRUSH pedzel = CreateSolidBrush(RGB(255, 0, 0));
    HBRUSH pedzel1 = CreateSolidBrush(RGB(255, 255, 0));
    HBRUSH pedzel2 = CreateSolidBrush(RGB(255, 255, 150));
    HBRUSH pedzel3 = CreateSolidBrush(RGB(0, 255, 0));
    HBRUSH pedzel4 = CreateSolidBrush(RGB(0, 255, 255));
    HBRUSH pedzel5 = CreateSolidBrush(RGB(100, 100, 100));

    SelectObject(kontekst, pedzel1);
    Pie(kontekst, 50, 50, 500, 500, 50, 200, 50, 400);
    SelectObject(kontekst, pedzel2);
    Pie(kontekst, 50, 50, 500, 500, 50, 400, 500, 400);
    SelectObject(kontekst, pedzel3);
    Pie(kontekst, 50, 50, 500, 500, 500, 400, 500, 200);
    SelectObject(kontekst, pedzel4);
    Pie(kontekst, 50, 50, 500, 500, 500, 200, 50, 200);

    SelectObject(kontekst, pedzel1);
    POINT literaC[8] = {
        {100, 100},
        {400, 100},
        {400, 200},
        {360, 200},
        {360, 150},
        {160, 150},
        {160, 420},
        {100, 420}};

    POINT literaC2[6] = {
        {160, 360},
        {360, 360},
        {360, 320},
        {400, 320},
        {400, 420},
        {160, 420}};

    pedzel = CreateSolidBrush(RGB(255, 0, 0));
    SelectObject(kontekst, pedzel);

    Polygon(kontekst, literaC, 8);
    SelectObject(kontekst, pedzel4);
    Polygon(kontekst, literaC2, 6);

    POINT Bez[13] = {
        800, 200,
        850, 50,
        1040, 50,
        1000, 230,
        970, 350,
        900, 320,
        800, 450,
        700, 320,
        630, 320,
        600, 230,
        560, 50,
        750, 50,
        800, 200

    };

    SelectObject(kontekst, pedzel1);
    PolyBezier(kontekst, Bez, 13);
    Ellipse(kontekst, 0, 0, 0, 0);

    DeleteObject(pedzel);

    //	HPEN pioro = CreatePen(PS_SOLID, 10, RGB(255,0,0));
    //	SelectObject(kontekst, pioro);

    //	MoveToEx(kontekst, 100, 300, NULL);
    //	LineTo(kontekst, 800, 300);

    //	DeleteObject(pioro);

    // utworzenie obiektu umo�liwiaj�cego rysowanie przy u�yciu GDI+
    // (od tego momentu nie mo�na u�ywa� funkcji GDI

    // MIEJSCE NA KOD GDI+

    // utworzenie czcionki i wypisanie tekstu na ekranie
    // FontFamily  fontFamily(L"Times New Roman");
    // Font        font(&fontFamily, 24, FontStyleRegular, UnitPixel);
    // PointF      pointF(100.0f, 400.0f);
    //	SolidBrush  solidBrush(Color(255, 0, 0, 255));

    // grafika.DrawString(L"To jest tekst napisany za pomoc� GDI+.", -1, &font, pointF, &solidBrush);

    //	EndPaint(okno, &paint);

    return 0;
  }

  case WM_DESTROY: // obowi�zkowa obs�uga meldunku o zamkni�ciu okna
    PostQuitMessage(0);
    return 0;

  default: // standardowa obs�uga pozosta�ych meldunk�w
    return DefWindowProc(okno, kod_meldunku, wParam, lParam);
  }
}
