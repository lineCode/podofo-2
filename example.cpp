#include <iostream>
#include <podofo/podofo.h>

using namespace PoDoFo;

void PrintHelp(std::string progname){
	std::cout << "hello podofo World!" << std::endl;
	std::cout << "usage: " << progname << " [outfile.pdf]"  << std::endl;
}

void HelloWorld(const char* pszFileName) {
	PdfStreamedDocument document(pszFileName); //PdfDocument : modify 
	PdfPainter painter;  // text and graphic onto PdfPage
	PdfPage* pPage; // multiple PdfPage to a file
	PdfFont* pFont; // required object
	
	try{
		pPage = document.CreatePage(
			PdfPage::CreateStandardPageSize(ePdfPageSize_A4));
		if(!pPage) {
			PODOFO_RAISE_ERROR( ePdfError_InvalidHandle );
		}

		painter.SetPage( pPage );
		pFont = document.CreateFont( "Arial" );
		if( !pFont ) {
			PODOFO_RAISE_ERROR( ePdfError_InvalidHandle );
		}
		pFont->SetFontSize( 18.0 );
		painter.SetFont( pFont );
		painter.SetColor( 0.0, 1.0, 0.0) ;
		painter.DrawText( 56.69, pPage->GetPageSize().GetHeight() - 56.69,
			"Hello PoDoFo World!" );
		painter.FinishPage();
		
		document.GetInfo()->SetCreator ( PdfString("example podofo test application") );
		document.GetInfo()->SetAuthor ( PdfString("Richard") );
		document.GetInfo()->SetTitle  ( PdfString("Hello World Title")  ) ;
		document.GetInfo()->SetSubject( PdfString("Testing Podofo") );
		document.GetInfo()->SetKeywords( PdfString("Test;PDF;Podofo;") );

		document.Close();
 	} catch ( const PdfError & e ) {
		try {
			painter.FinishPage();
		} catch ( ... ) {
			
		}
		
		throw e;
	}
}

int main(int argc, char** argv) {
	if (argc!=2) {
		PrintHelp(argv[0]);
		return -1;
	}

	try {
		HelloWorld( argv[1] );
	} catch ( const PdfError& eCode ) {
		eCode.PrintErrorMsg();
		return eCode.GetError();
	}

	PdfEncodingFactory::FreeGlobalEncodingInstances();
	std::cout << std::endl
				<< "created pdf : " << argv[1] << std::endl << std::endl;
	return 0;
}

	
	
