#include <iostream>

using namespace std;

class Currency {
public:
  float dollarAmt;
  float nprAmt;
  const int dollarValue = 132;

  void usdToNpr() {
    float convertedNpr = dollarAmt * dollarValue;
    cout << "USD to NPR value :" << convertedNpr << endl;
  };

  void nprToUsd() {
    float convertedUsd = nprAmt / dollarValue;
    cout << "NPR to USD value :" << convertedUsd << endl;
  }


  void getInputValue() {
    cout << "Enter the dollar input: ";
    cin >>  dollarAmt;
    cout << "Enter the NPR amount: " ;
    cin >>  nprAmt;
  }
};

int main() {
  Currency c;
  c.getInputValue();
  c.usdToNpr();
  c.nprToUsd();

}
