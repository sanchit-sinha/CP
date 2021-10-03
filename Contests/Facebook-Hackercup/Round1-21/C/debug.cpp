string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

// added manually
// 1-D arrays
template < typename indexl, typename indexr>
void debug_out(long double A[], indexl l, indexr r) {
  int x = l, y = r;
  for (int i = x; i <= y; i++) {
    cerr << "(" << i << " " << A[i] << ") ";
  }
  cerr << "\n";
}

template < typename indexl, typename indexr>
void debug_out(long long A[], indexl l, indexr r) {
  int x = l, y = r;
  for (int i = x; i <= y; i++) {
    cerr << "(" << i << " " << A[i] << ") ";
  }
  cerr << "\n";
}

template < typename indexl, typename indexr>
void debug_out(int A[], indexl l, indexr r) {
  int x = l, y = r;
  for (int i = x; i <= y; i++) {
    cerr << "(" << i << " " << A[i] << ") ";
  }
  cerr << "\n";
}
