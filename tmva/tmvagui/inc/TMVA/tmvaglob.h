#ifndef tmvaglob__HH
#define tmvaglob__HH
// global TMVA style settings
#ifndef TMVA_TMVAGLOB
#define TMVA_TMVAGLOB

#include <iostream>
#include <vector>

#include "TPad.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TSystem.h"
#include "TImage.h"
#include "TKey.h"
#include "TH1.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TFile.h"
#include "TDirectory.h"
#include "TObjArray.h"
#include "TClass.h"
#include "TText.h"
#include "TLegend.h"

#include "RVersion.h"

namespace TMVA{

   using std::cout;
   using std::endl;

   namespace TMVAGlob {
         // --------- S t y l e ---------------------------
      // -----------------------------------------------
      
      enum TypeOfPlot { kId = 0,
                        kNorm,
                        kDecorrelated,
                        kPCA,
                        kGaussDecorr,
                        kNumOfMethods };
      
      static Int_t c_Canvas         = TColor::GetColor( "#f0f0f0" );
      static Int_t c_FrameFill      = TColor::GetColor( "#fffffd" );
      static Int_t c_TitleBox       = TColor::GetColor( "#5D6B7D" );
      static Int_t c_TitleBorder    = TColor::GetColor( "#7D8B9D" );
      static Int_t c_TitleText      = TColor::GetColor( "#FFFFFF" );
      static Int_t c_SignalLine     = TColor::GetColor( "#0000ee" );
      static Int_t c_SignalFill     = TColor::GetColor( "#7d99d1" );
      static Int_t c_BackgroundLine = TColor::GetColor( "#ff0000" );
      static Int_t c_BackgroundFill = TColor::GetColor( "#ff0000" );
      static Int_t c_NovelBlue      = TColor::GetColor( "#2244a5" );
      
      
      // set the style
      void SetSignalAndBackgroundStyle( TH1* sig, TH1* bkg, TH1* all = 0 ); 
      void SetMultiClassStyle( TObjArray* hists ); 
      // set frame styles
      void SetFrameStyle( TH1* frame, Float_t scale = 1.0 );
      void SetTMVAStyle();
      void DestroyCanvases();
      // set style and remove existing canvas'
      void Initialize( Bool_t useTMVAStyle = kTRUE );
      // checks if file with name "fin" is already open, and if not opens one
      TFile* OpenFile( const TString& fin );
      // used to create output file for canvas
      void imgconv( TCanvas* c, const TString & fname );
      TImage * findImage(const char * imageName) ;
      void plot_logo( Float_t v_scale = 1.0, Float_t skew = 1.0 );
      void NormalizeHist( TH1* h ); 
      void NormalizeHists( TH1* sig, TH1* bkg = 0 ); 
      void GetMethodName( TString & name, TKey * mkey ); 
      void GetMethodTitle( TString & name, TKey * ikey ) ;
      void GetMethodName( TString & name, TDirectory * mdir ); 
      void GetMethodTitle( TString & name, TDirectory * idir ) ;
      TKey *NextKey( TIter & keyIter, TString className); 
      UInt_t GetListOfKeys( TList& keys, TString inherits, TDirectory *dir=0 );
      Int_t GetNumberOfTargets( TDirectory *dir );
      Int_t GetNumberOfInputVariables( TDirectory *dir );
      std::vector<TString> GetInputVariableNames(TDirectory *dir );
      Int_t GetNumberOfInputVariablesMultiClass( TDirectory *dir );
      std::vector<TString> GetClassNames(TDirectory *dir );
      TKey* FindMethod( TString name, TDirectory *dir=0 );
      Bool_t ExistMethodName( TString name, TDirectory *dir=0 );
      UInt_t GetListOfMethods( TList & methods, TDirectory *dir=0 );
      UInt_t GetListOfJobs( TFile* file, TList& jobdirs);
      UInt_t GetListOfTitles( TDirectory *rfdir, TList & titles );
      UInt_t GetListOfTitles( TString & methodName, TList & titles, TDirectory *dir=0 );
      TDirectory *GetInputVariablesDir( TMVAGlob::TypeOfPlot type, TDirectory *dir=0 );
      TDirectory *GetCorrelationPlotsDir( TMVAGlob::TypeOfPlot type, TDirectory *dir=0 );
      
   }
   
#endif
}
#endif