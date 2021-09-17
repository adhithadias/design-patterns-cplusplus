#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Token {
    enum Type {integer, plus, minus, lparen, rparen} type;
    string text;

    Token(Type type, const string &text) : type(type), text(text) {}

    friend ostream &operator<< (ostream &os, const Token &token) {
        os << " " << token.text << " ";
        return os;
    }
};

vector<Token> lex(const string& input) {
    vector<Token> result;

    for (int i=0; i < input.size(); i++) {
        switch (input[i]) {
            case '+':
                result.push_back(Token{Token::plus, "+"});
                break;
            case '-':
                result.push_back(Token{Token::minus, "-"});    
                break;
            case '(':
                result.push_back(Token{Token::lparen, "("});    
                break;
            case ')':
                result.push_back(Token{Token::rparen, ")"});    
                break;
            default:
                ostringstream buffer;
                buffer << input[i];
                for (int j=i+1; j<input.size(); j++) {
                    if (isdigit(input[j])) {
                        buffer << input[j];
                        ++i;
                    } 
                    else {
                        result.push_back(Token{Token::integer, buffer.str()});
                        break;
                    }
                }
                break;
        }
    }

    return result;
};

int main() {

    string input{"(13-4)-(12+1)"};
    auto tokens = lex(input);

    for (auto& t : tokens) {
        cout << t << " ";
    }
    cout << endl;


    return 0;
};