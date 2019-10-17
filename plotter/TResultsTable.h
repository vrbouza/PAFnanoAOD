#ifndef TRESULTSTABLE_H
#define TRESULTSTABLE_H

#include <iostream>
#include "TString.h"

enum ETResultsTableOutputFormat {kPlain, kLaTeX, kHTML, kCSV};
Int_t iColor = 0;

TString KeepAllErrorDecimals(Double_t number, Double_t error = 0);
TString KeepOneDecimal(Double_t number, Double_t error = 0);

class TResultsTableContent {
 public:
  //TResultsTableContent(Double_t content = 0) {fContent = content; fError = 0; fStatError = 0;}
  TResultsTableContent(Double_t content = 0) {fContent = content; fError = 0; fStatError = 0; fString = ""; activate = true;}

  Double_t Content() const {return fContent;}
  Double_t& Content() {return fContent;}
  Double_t Error() const {return fError;}
  Double_t& Error() {return fError;}
  Double_t StatError() const {return fStatError;}
  Double_t& StatError() {return fStatError;}
  TString& String() { return fString;}

  void SetContent(Double_t c) {fContent = c;}
  void SetError(Double_t e) {fError = e;}
  void SetStatError(Double_t e) {fStatError = e;}
  void SetString(TString t){ fString = t;}
  void Activate(Bool_t d = true){ activate = d;}

  operator Double_t() const {return fContent;}
  operator Double_t() {return fContent;}

 protected:
  Double_t fContent;
  Double_t fError;
  Double_t fStatError;
  TString fString;
  Bool_t activate;
};

class TResultsTableRow {
 public:
  TResultsTableRow(UInt_t ncol=0);
  ~TResultsTableRow() {if (fRow) delete[] fRow;}

  TResultsTableContent& operator[](UInt_t i) {return fRow[i];}
  TResultsTableContent  operator[](UInt_t i) const {return fRow[i];}

  

  UInt_t GetNColumns() const {return fNColumns;}
  void SetNColumns(UInt_t ncols);

 protected:
  TResultsTableContent*  fRow;
  UInt_t fNColumns;
};


class TResultsTable {
 public:
  TResultsTable(UInt_t nrows, UInt_t ncols, Int_t witherrors = 0);
  ~TResultsTable() {if (fRows) delete[] fRows;}

  ////////////////////////////////////////////////////////////////////////////
  //
  // Operator []
  // These will allow to recover a row and from there a cell to access the
  // content. Examples:
  // + sometable[i][j] will return the value stored in cell_ij
  // + sometable[i][j].Content() is equivalente to the previous line
  // + sometable[i][j].Error() will return the error stored in cell_ij
  //
  TResultsTableRow& operator[](UInt_t i) {return fRows[i];}
  TResultsTableRow  operator[](UInt_t i) const {return fRows[i];}
  //
  ////////////////////////////////////////////////////////////////////////////

  ////////////////////////////////////////////////////////////////////////////
  //
  // Some options
  //

  // Set it to true if your want all lines to be drawn (horizontal or vertical)
  // Default value is false
  void SetDrawHLines(Bool_t draw = false) {fDrawHLines = draw;}
  void SetDrawVLines(Bool_t draw = false) {fDrawVLines = draw;}
  // Set the width of each content column
  void SetPlainTextColumnWidth(UInt_t w) {fColumnWidth = w;}
  //
  ////////////////////////////////////////////////////////////////////////////


  ////////////////////////////////////////////////////////////////////////////
  //
  // Saving and printing
  //
  void SaveAs(const TString& filename) const;  
  void Print(ETResultsTableOutputFormat format = kPlain, ostream& os=std::cout) const;
  //
  ////////////////////////////////////////////////////////////////////////////

  ////////////////////////////////////////////////////////////////////////////
  //
  // Some getters and setters
  //
  void SetContent(UInt_t i, UInt_t j, Double_t value) {fRows[i][j] = value;}
  void SetRowTitle(UInt_t i, TString title) {fRowTitle[i] = title;}
  void SetColumnTitle(UInt_t j, TString title) {fColumnTitle[j] = title;}
  void SetRowTitleHeader(const char* str) { fRowTitleHeader = str;}
 

  UInt_t GetNColumns() const { return fNColumns;}
  UInt_t GetNRows() const { return fNRows;}

  Double_t GetContent(UInt_t i, UInt_t j) const {return fRows[i][j];}
  TString GetRowTitle(UInt_t i) const {return fRowTitle[i];}
  TString GetColumnTitle(UInt_t j) const {return fColumnTitle[j];}
  TString GetRowTitleHeader() const { return fRowTitleHeader;}
  //
  ////////////////////////////////////////////////////////////////////////////
  void SetFormatNum(TString k){ formatNum = k;}
  void AddVSeparation(TString t){VSeparations += TString(", ") + t;}
  void AddVSeparation(Int_t g){ VSeparations += TString(Form("l%i,", g));} // Separation between rows g and g+1
  TString getCellColor(Int_t col) const;

 protected:
  TString FixWidth(const TString& s, UInt_t width=11, Bool_t prepend = true) const;

  TString formatNum;
  UInt_t fNColumns; //Number of columns
  UInt_t fNRows;    //Number of rows

  TString colorRow[20] = {"#0099cc", "#ff9966", "#99ff99", "#ff66ff", "#99cc00", "#0099cc", "#ff9966", "#99ff99", "#ff66ff", "#99cc00", "#0099cc", "#ff9966", "#99ff99", "#ff66ff", "#99cc00", "#0099cc", "#ff9966", "#99ff99", "#ff66ff", "#99cc00"};
  TString color[20]    = {"#ccffff", "#ffffcc", "#ccffcc", "#ffccff", "#ccff99", "#ccffff", "#ffffcc", "#ccffcc", "#ffccff", "#ccff99", "#ccffff", "#ffffcc", "#ccffcc", "#ffccff", "#ccff99", "#ccffff", "#ffffcc", "#ccffcc", "#ffccff", "#ccff99"};
  //TString colorRow[20];
  //TString color[20]; 
  Int_t fWithErrors;
  TString VSeparations;

  TResultsTableRow* fRows;    //The table rows (content)

  TString     fRowTitleHeader; //String to put on top of row titles

  TString*    fRowTitle;    //Each row title
  TString*    fColumnTitle; //Each columnt title

  //Options
  Bool_t fDrawHLines;
  Bool_t fDrawVLines;
  UInt_t fColumnWidth;
};


#endif
