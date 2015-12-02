#include <iostream>
#include <complex>
#include <regex>
#include "cmdline.h"

//template<class _Scalar>
//struct 

using namespace std;
typedef complex<double> cd;

template<class T, class Label>
void check(const Label& label, T a, T b) {
  double eps(std::pow(10.0, -10.0));

  cout << label << ": ";
  if(abs(a-b) < eps)
    cout << "ok" << endl;
  else
    cout << "failed" << endl;
  
}
void check_complex() {

  string arg("1.234+0.2j");
  check(1,
	cmdline::detail::lexical_cast<cd, string>(arg),
	cd(1.234, 0.2));

  string arg1("1.234-0.2j");
  check(2,
	cmdline::detail::lexical_cast<cd, string>(arg1),
	cd(1.234, -0.2));
  
}

int main(int argc, char *argv[]) {
  
  check_complex();

  cmdline::parser a;
  a.add<cd>("cval", 'c', "complex", true, cd(0.0));

  a.parse_check(argc, argv);

  cout << a.get<cd>("cval") << endl;

}

