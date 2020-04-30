char CONVtoCHAR(String str){
   if     (str == ".-")   {return 'a' ;}
   else if(str == "-...")   {return 'b' ;}
   else if(str == "-.-.")   {return 'c' ;}
   else if(str == "-..")   {return 'd' ;}
   else if(str == ".")   {return 'e' ;}
   else if(str == "..-.")   {return 'f' ;}
   else if(str == "--.")   {return 'g' ;}
   else if(str == "....")   {return 'h' ;}
   else if(str == "..")   {return 'i' ;}
   else if(str == ".---")   {return 'j' ;}
   else if(str == "-.-")   {return 'k' ;}
   else if(str == ".-..")   {return 'l' ;}
   else if(str == "--")   {return 'm' ;}
   else if(str == "-.")   {return 'n' ;}
   else if(str == "---")   {return 'o' ;}
   else if(str == ".--.")   {return 'p' ;}
   else if(str == "--.-")   {return 'q' ;}
   else if(str == ".-.")   {return 'r' ;}
   else if(str == "...")   {return 's' ;}
   else if(str == "-")   {return 't' ;}
   else if(str == "..-")   {return 'u' ;}
   else if(str == "...-")   {return 'v' ;}
   else if(str == ".--")   {return 'w' ;}
   else if(str == "-..-")   {return 'x' ;}
   else if(str == "-.--")   {return 'y' ;}
   else if(str == "--..")   {return 'z' ;}
   else if(str == "-----")   {return '0' ;}
   else if(str == ".----")   {return '1' ;}
   else if(str == "..---")   {return '2' ;}
   else if(str == "...--")   {return '3' ;}
   else if(str == "....-")   {return '4' ;}
   else if(str == ".....")   {return '5' ;}
   else if(str == "-....")   {return '6' ;}
   else if(str == "--...")   {return '7' ;}
   else if(str == "---..")   {return '8' ;}
   else if(str == "----.")   {return '9' ;}
   else if(str == ".-.-.-")   {return '.' ;}
   else if(str == "--..--")   {return 44 ;}
   else if(str == "..--..")   {return '?' ;}
   else if(str == ".----.")   {return 39;}
   else if(str == "-.-.--")   {return '!' ;}
   else if(str == "-..-.")   {return '/' ;}
   else if(str == "-.--.")   {return '(' ;}
   else if(str == "-.--.-")   {return ')' ;}
   else if(str == ".-...")   {return '&' ;}
   else if(str == "---...")   {return ':' ;}
   else if(str == "-.-.-.")   {return ';' ;}
   else if(str == "-...-")   {return '=' ;}
   else if(str == ".-.-.")   {return '+' ;}
   else if(str == "-....-")   {return '-' ;}
   else if(str == "..--.-")   {return '_' ;}
   else if(str == ".--.-.")   {return '@' ;}
   else if(str == ".-..-.")   {return '"' ;}
   else if(str == "...-.")   {return '*' ;}
   else if(str == "-.-.-")   {return 92;}
   else if(str == "---.-")   {return '%' ;}
   else if(str == "--.-.")   {return '#' ;}
   else if(str == "--.-.-")   {return '|' ;}
   else if(str == "......")   {return '^' ;}
   else if(str == ".---..")   {return '~' ;}
   else if(str == "-..-.-")   {return '`' ;}
   else if(str == "...-..")   {return '$' ;}
   else if(str == ".--..")   {return '[' ;}
   else if(str == ".--..-")   {return ']' ;}
   else if(str == ".--.-")   {return '{' ;}
   else if(str == ".--.--")   {return '}' ;}
   else if(str == "-.---")   {return '<' ;}
   else if(str == "-.----")   {return '>' ;}
   else if(str == "..--")   {return 32 ;}
   else if(str == ".-.-")   {return 176;}
   else if(str == "....-.")   {return 129;}
   else if(str == "----")   {return 178;}
   else  {return 178;}            //default: BACKSPACE  
}
