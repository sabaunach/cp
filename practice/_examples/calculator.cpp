#include <bits/stdc++.h>

using namespace std;

uint32_t nlpo2(uint32_t x) {
    x |= (x >> 1); x |= (x >> 2);
    x |= (x >> 4); x |= (x >> 8);
    x |= (x >> 16); return x + 1;
}

typedef enum {ident, number, lparen, rparen, times,
              slash, plussym, minussym, eql, neq, lss,
              leq, gtr, geq, callsym, beginsym,
              semicolon, endsym, ifsym, whilesym,
              becomes, thensym, dosym, constsym, comma,
              varsym, procsym, period, oddsym} Symbol;
unordered_map<string, Symbol> mp = {
        {"(", lparen}, {")", rparen},
        {"*", times}, {"/", slash},
        {"+", plussym}, {"-", minussym},
        {"=", eql}, {"!=", neq},
        {"<", lss}, {"<", leq},
        {";", semicolon}, {"=", becomes},
        {"=", ident}, {",", comma}};
Symbol sym; string val;
void nextsym() { // probably this
    string s; cin >> s;
}
double factor();
void error(const char msg[]);
int accept(Symbol s) {
    if (sym == s) { nextsym(); return 1; } return 0; }

int expect(Symbol s) { if (accept(s)) return 1;
    error("expect: unexpected symbol"); return 0;
}

double term() { factor();
    while (sym == times || sym == slash) {
        nextsym(); factor(); } }

void expression() {
    if (sym == plussym || sym == minussym) nextsym();
    term(); while (sym == plussym || sym == minussym) {
        nextsym(); term(); } }

double factor() {
    if (accept(ident)) { ; // ident := expression
    } else if (accept(number)) {
        ; // return stod(val);
    } else if (accept(lparen)) {
        expression(); expect(rparen);
    } else {
        error("factor: syntax error"); nextsym();
} }

void condition() {
    if (accept(oddsym)) { expression();
    } else { expression();
        if (sym == eql || sym == neq || sym == lss ||
        sym == leq || sym == gtr || sym == geq) {
            nextsym(); expression();
        } else {
            error("condition: invalid operator");
            nextsym(); } } }

void statement() {
    if (accept(ident)) {
        expect(becomes); expression();
    } else if (accept(callsym)) { expect(ident);
    } else if (accept(beginsym)) {
        do { statement();
        } while (accept(semicolon));
        expect(endsym);
    } else if (accept(ifsym)) {
        condition(); expect(thensym); statement();
    } else if (accept(whilesym)) {
        condition(); expect(dosym); statement();
    } else {
        error("statement: syntax error");
        nextsym(); } }

void block() {
    if (accept(constsym)) {
        do {
            expect(ident); expect(eql);
            expect(number);
        } while (accept(comma));
        expect(semicolon);
    }
    if (accept(varsym)) {
        do { expect(ident);
        } while (accept(comma));
        expect(semicolon);
    }
    while (accept(procsym)) {
        expect(ident); expect(semicolon);
        block(); expect(semicolon);
    } statement();
}

void program(void) {
    nextsym();
    block();
    expect(period);
}
