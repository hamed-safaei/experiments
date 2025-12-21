import string

# -------------------------------
# KEYWORDS & OPERATORS
# -------------------------------

KEYWORDS = {
    "alignas","alignof","and","and_eq","asm","auto","bitand","bitor","bool",
    "break","case","catch","char","char8_t","char16_t","char32_t","class",
    "compl","concept","const","consteval","constexpr","constinit","continue",
    "co_await","co_return","co_yield","decltype","default","delete","do",
    "double","dynamic_cast","else","enum","explicit","export","extern","false",
    "float","for","friend","goto","if","inline","int","long","mutable",
    "namespace","new","noexcept","not","not_eq","nullptr","operator","or",
    "or_eq","private","protected","public","register","reinterpret_cast",
    "requires","return","short","signed","sizeof","static","static_assert",
    "static_cast","struct","switch","template","this","thread_local","throw",
    "true","try","typedef","typeid","typename","union","unsigned","using",
    "virtual","void","volatile","wchar_t","while","xor","xor_eq","std" , "cin" , "count" , "if"
}

OPERATORS = {
    "++","--","=","+=","-=","*=","/=","%=",
    "&=","|=","^=","<<=",">>=",
    "==","!=","<",">","<=",">=",
    "&&","||","!","&","|","^","~",
    "<<",">>","+","-","*","/","%",
    "->","->*",".*",
    "?",
    ":",
    ",",
    "()",
    "[]"
}

# -------------------------------
# Helper functions
# -------------------------------

def is_keyword(token):
    if token.strip() == "":
        return
    if token in KEYWORDS:
        print(f"Is keyword({token})")
    else:
        print(f"Is ID({token})")


def is_operator(token):
    if token in OPERATORS:
        print(f"Is operator({token})")
        return True
    return False


# -------------------------------
# Main evaluator 
# -------------------------------

def evaluate(c, state, token):
    match state:

        # ---------------- STATE 0 -------------------
        case 0:
            if c.isspace() or c == ";":
                is_keyword(token)
                return 0, ""
            elif c.isalpha():
                return 1, token + c
            elif c.isdigit():
                return 3, token + c
            elif c in "+-*/=<>&|!":
                return 6, token + c
            elif c in "{}()":
                print(f"Is Seperator({c})")
                return 0, ""
            else:
                return -1, token

        # -------------- STATE 1 (ID / KEYWORD) -------
        case 1:
            if c.isspace() or c == ";":
                is_keyword(token)
                return 0, ""
            elif c.isalnum() or c == "_":
                return 1, token + c
            elif c == "(":
                return 7, token + c
            elif c in "+-":
                print(f"Is ID({token})")
                return 6, c
            else:
                return -1, token

        # -------------- STATE 3 (INTEGER) ------------
        case 3:
            if c.isspace() or c == ";":
                print(f"Is integer({token})")
                return 0, ""
            elif c.isdigit():
                return 3, token + c
            elif c == ".":
                return 4, token + c
            else:
                return -1, token

        # ------------ STATE 4 (dot in real) ----------
        case 4:
            if c.isdigit():
                return 5, token + c
            else:
                return -1, token

        # ------------ STATE 5 (REAL number) ----------
        case 5:
            if c.isdigit():
                return 5, token + c
            elif c.isspace() or c == ";":
                print(f"Is Real({token})")
                return 0, ""
            else:
                return -1, token

        # -------------- STATE 6 (OPERATOR) -----------
        case 6:
            if c in "=+-*/&|<>":
                token += c
                return 6, token
            else:
                if not is_operator(token):
                    return -1, token
                return 0, ""

        # -------------- STATE 7 (Function) -----------
        case 7:
            if c == ")":
                print(f"Is Function({token})")
                return 0, ""
            else:
                return -1, token

    return state, token


#Main

def main():

    path = r"C:\Users\Aria\OneDrive\Desktop\experiments\test.cpp"

    try:
        with open(path, "r") as f:
            lines = f.readlines()
    except:
        print("Failed to open the file!")
        return


    program = ""
    for line in lines:
        if line.startswith("#"):
            continue
        program += line + "\n"

    
    state = 0
    token = ""

    for c in program:
        state, token = evaluate(c, state, token)
        if state == -1:
            print("Syntax Error!")
            return

    if state == -1:
        print("Syntax Error!")


if __name__ == "__main__":
    main()
