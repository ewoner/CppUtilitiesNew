#include "string_utilities.hpp"

#include <iostream>
// using std::cerr;
// using std::endl;

namespace ewoner {
namespace utilities {

std::string capitalize(std::string_view sv) {
  std::string s{sv};
  s[0] = std::toupper(s[0]);
  return s;
}
std::string trim(const std::string_view sv) {

  size_t first = sv.find_first_not_of(WHITE_SPACE);
  size_t last = sv.find_last_not_of(WHITE_SPACE);
  return std::string{sv.substr(first, last - first + 1)};
}
std::string change_case(const std::string_view sv) {
  std::string rv{sv};
  for (char &c : rv) {
    if (c >= 'a' && c <= 'z') {
      c = std::toupper(c);
    } else {
      c = std::tolower(c);
    }
  }
  return rv;
}
std::string title_case(const std::string_view sv) {
  std::string rv{sv};
  bool space_flag = true;
  for (auto &c : rv) {
    if (WHITE_SPACE.find(c) < WHITE_SPACE.size()) {
      space_flag = true;
    } else if (space_flag) {
      space_flag = false;
      c = std::toupper(c);
    } else {
      c = std::tolower(c);
    }
  }
  return rv;
}

std::string lower_case(const std::string_view sv) {
  std::string rv{sv};
  for (char &c : rv) {
    c = std::tolower(c);
  }
  return rv;
}

std::string upper_case(const std::string_view sv) {
  std::string rv{sv};
  for (char &c : rv) {
    c = std::toupper(c);
  }
  return rv;
}

void clear_istream(std::istream &is) {
  std::string s{};
  is.clear();
  while (getline(is, s))
    ;
}

std::ostream &put_prompt(std::ostream &os, const std::string_view s,
                         const std::string_view s2 = {}) {
  if (s2.size() < 0) {
    os << s << " (" << s2 << "): ";
  } else {
    os << s << ": ";
  }
  os.flush();
  return os;
}

std::vector<std::string> split(const std::string_view &s,
                               const std::string_view &delim) {
  /*
    if  ( delim == WHITE_SPACE ) {
      clog << __func__ << "start with " << s << " and delim |'WHITE_SPACE'|" <<
  endl;
  }
  else {
    clog << __func__ << "start with " << s << " and delim |" << delim << "|" <<
  endl;
  }
  */
  std::vector<std::string> vecs;
  size_t curr = 0;
  size_t found = s.find_first_of(delim, curr);
  int x = 0;
  while (found < s.size() && x < 5) {
    found = s.find_first_of(delim, curr);
    // clog << "curr->" << curr << endl;
    // clog << "found->" << found << endl;
    // clog << s.substr(curr, found - curr) << endl;
    vecs.emplace_back(s.substr(curr, found - curr));
    curr = found + 1;
    x++;
  }
  // clog << __func__ << " returning " << vecs.size() << " elements" << endl;
  return vecs;
}
} // namespace utilities
} // namespace ewoner
