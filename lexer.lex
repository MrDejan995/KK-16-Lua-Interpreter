%option noyywrap
%option nounput
%{
#include <iostream>
#include <string>
#include <cstdlib>

#include "izraz.hpp"
#include "naredba.hpp"

#include "parser.tab.hpp"

%}

DIGIT [0-9]

%%
print               return print_token;
read           			return read_token;
if                  return if_token;
else                return else_token;
while               return while_token;
end                 return end_token;
and									return and_token;
or									return or_token;
not									return not_token;
do									return do_token;
than								return than_token;
--\[\[(.*)|(\n)--\]\]-- {
    // Komentare ignorisemo.
}
"==" {
    return jednako_token;
}

"~=" {
    return nejednako_token;
}

{DIGIT}+([.]{DIGIT}+)? {
    yylval.br = atof(yytext);
    return num_token;
}
[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.str = new std::string(yytext);
    return id_token;
}

[\n#;=+><()*/^-] return *yytext;

[ \t] {

}

. {
    std::cerr << "Lexical error. Unrecognized character: " << *yytext << std::endl;
    exit(EXIT_FAILURE);
}
%%
