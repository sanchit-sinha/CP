vector<int> KMP_Prefix_Function (const string &S){
 vector<int> pfx (int (S.length()) + 1);
 pfx[1] = 0;
 for (int i = 2; i < (int) pfx.size(); i++){
  int Q = pfx[i - 1];
  while (Q > 0 && S[i - 1] != S[Q]) Q = pfx[Q];
  if (S[Q] == S[i - 1]) pfx[i] = Q + 1;
  else pfx[i] = 0;
 }
 return pfx;
}
 
int getshift (const vector<int> &Kmp , const string &T , const string &S){
 int chars_matched = 0;
 for (int i = 0; i < (int) T.length(); i++){
  // while the next character doesn't match
  while (chars_matched > 0 && S[chars_matched] != T[i]){
   chars_matched = Kmp[chars_matched];
  }
  // we matched an extra character
  if (S[chars_matched] == T[i]) ++chars_matched;
  // all characters matched
  if (chars_matched == (int) S.length()){
   return i - chars_matched + 1;
  }
 }
 return -1;
}