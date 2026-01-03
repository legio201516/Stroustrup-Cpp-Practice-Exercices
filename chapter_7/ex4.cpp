
/*  Simple calculator
    This program implements a basic calculator.
    Input from cin,output to cout.

    The grammar for the input is : 
    Calculation : 
    Statement
    Print 
    Quit
    Calculation Statement

    Statement : 
    Declaration
    Expression
	Affectation

    Declaration : 
    "let" Name "=" Expression

	Affectation : 
	Name "=" Number
	 
    Expression : 
    Term
    Expression + term
    Expression - term
    
    Term : 
    Primary 
    Term *Primary
    Term /Primary
    Term %Primary

 
    Primary : 
    Number
    (Expression)
    -Primary
    +Primary
	Name = Expression
    sqrt(Expression)
    pow(Expression)

    Number : 
    Floating point litteral
*/

#include "std_lib_facilities.h"
// 
struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
    Token(char ch, string s) :kind(ch), name(s){}
};

class Token_stream {
private :
	bool full;
	Token buffer;
public:
	Token_stream() :full(false), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true;  }

	void ignore(char);
};


const char let = 'L';// mot clé de déclaration
const string quit = "quit";
const char quiting = 'q';
const char print = ';';
const char number = '8';
const char var = 'v';
const char con = 'C';// lexeme de nom
const string declkey = "#";// lexeme de déclaration
const string constkey = "const";

const char name_type = 'A';
const string sqr= "sqrt";
const string power="pow";

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	while (isspace(ch)){
		if (ch=='\n')
			 return Token (print);
		cin.get(ch);
}
	switch (ch) {
    case ',':
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case print :
	case '=':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}
    case '#':
        return Token(let);	// mot clé de déclaration
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)|| ch=='_' )){s += ch;}// we build the string(variable?, func name?..)
			cin.unget();
			if (s==constkey) return Token(con);
            if (s==quit) return Token (quiting);
            if (s==sqr) return Token('s');// Now if s== sqrt we return token of sqrt(val)
            if (s==power) return Token('p');
            return Token(name_type, s);// if it's just a variable we create a token with type name,and string s

		}
		error("Bad token");
	}
}
double pow(double x, int i){
    if (x==0)return 0;
    int prod = 1;
    for (int j=1;j<=i; j++){
        prod*=x;
    }return prod;
}
void Token_stream::ignore(char c)
{// c is the type of Token
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;
	char ch=0;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	bool is_var;
	Variable(string n, double v, bool is) :name(n), value(v), is_var(is) { }
};

class Symbol_table {

	private : 
	vector<Variable> var_table;
	public :
	

	double get_value(string s);
	void set_value(string s, double d);
	double define_name(string var, double val, bool is_var);
	bool is_declared(string var);
};


	double Symbol_table::get_value(string s)
	{// gets value from variable named s
		for (int i = 0; i < var_table.size(); ++i)
			if (var_table[i].name == s) return var_table[i].value;
		error("get: undefined name ", s);
	}

	void Symbol_table::set_value(string s, double d)
	{// puts value d to the Variable named s
		for (int i = 0; i < var_table.size(); ++i)
			if (var_table[i].name == s) {
				if (var_table[i].is_var==false) error("trying to redefine a const !");
				var_table[i].value = d;
				return;
			}
		error("set: undefined name ", s);
	}
double Symbol_table::define_name(string var, double val, bool is_var){
    //adds (var, val, is_var) to var_table
    if (is_declared(var)) error(var, " declared twice");
    var_table.push_back(Variable(var,val, is_var));
    return val;
}

bool Symbol_table::is_declared(string var){// is var already declared ? 
    for (int i=0; i<var_table.size(); i++){
        if (var_table[i].name==var){
            return true;
        }
    } 
    return false;
}
Symbol_table st;
Token_stream ts;
double expression();



 
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("')' expected"); return d;
	}
	case '-':
		return -primary();
	case '+':
		return +primary();
	case number:
		return t.value;
	case name_type:{
		Token op  = ts.get();
		if (op.kind=='='){
			double d = expression();

			st.set_value(t.name,d );
			return d ; // set variable named t.name to value d.
		}
		else {ts.unget(op);
			return st.get_value(t.name);}// or if no affectation , just give the variable value.
		}

    case 's' : {
        t = ts.get();//get the first parenthesis of sqrt()
        double d = expression();// Then get the expression
        t = ts.get();
        if (t.kind != ')') {error("')' expected for srt()");}
        if (d<0)error("oopsie, sqrt of negativ number  doenst exist dummy ! ");// error if sqrt() not closed 
        return sqrt(d);
 		break;}

    case 'p': {
        t = ts.get();//get the first parenthesis of pow()
        double d = expression();// Then get the expression

        t = ts.get();// we get the comma
        if (t.kind != ',') error(" missing',' between pow() args ");

        double d2 = expression();
        int i = int(d2);
        if (d2!= i)error ("expected and int for i in the pow(x,i)");
        t = ts.get();// get the closing '('
        if (t.kind != ')') error("')' expected for pow(x,i)");//We get the int i of pow(x,i)
        if (d<0)error("oopsie, sqrt of negativ number  doenst exist dummy ! ");// error if sqrt() not closed 
        return pow(d,i);
 		break;   }
    
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	Token t = ts.get();// gets the next lexeme from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			{left *= primary();
            t=ts.get();
			break;}
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
        t=ts.get();
		break;
		}
        case '%': {
            double d =primary();
            int i1 =int(left);
            if(i1!=left) error("left hand operand of '%' not int");
            int i2 = int(d);
            if(i2!=d) error("right hand operand of '%' not int");
            left=i1%i2;
            t=ts.get();
            break;
        }
		default:{
			ts.unget(t);
			return left;
		}
	
}}}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}


double declaration(char k)
{//supposes we saw variable or const declaration key 
//handles name= expression, declares a variable named "name" with initial value "expression"
	Token t = ts.get();
	if (k!= con and k!=let) error("variable or const expected in declaration");
	string var_name = t.name;

    Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);
	double d = expression();
	st.define_name(var_name, d, k==let);// we define a new name with bool that indicates if const or variable
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let: case con:
		cout <<  "we got a token of type : "<<  t.kind << endl;
		return declaration(t.kind);

	default:
		ts.unget(t);
		return expression();
	}
}


void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();// deletes first all prints
		if (t.kind == quiting) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {
    st.define_name("pi", 3.141592, false);     // We first define names
    st.define_name("e", 2.71828, false);
    st.define_name("k", 1000, false ); 
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}