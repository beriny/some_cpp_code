/*
 *             File Name: textquery.cpp
 * Operating Environment: ubuntu linux
 *                Author: Jiang
 *                 Email: ligelaige@gmail.com
 *          Created Time: Mon 15 Dec 2014 09:07:19 AM  
 */

#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

typedef std::vector<std::string>::size_type line_no;

class TextQuery{
public:
        typedef std::vector<std::string>::size_type line_no;
        void read_file(std::ifstream &is){
                store_file(is);
                build_map();
        }
        std::set<line_no> run_query(const std::string&) const;
        std::set<line_no> run_query_plus(const std::string&) const;
        std::string text_line(line_no) const;
        
private:
        void store_file(std::ifstream&);
        void build_map();
        std::vector<std::string> lines_of_text;
        std::map<std::string, std::set<line_no> > word_map;
};

void TextQuery::store_file(std::ifstream& is) {
        string textline;
        while (getline(is, textline))
        {
                lines_of_text.push_back(textline);
        }
}

void TextQuery::build_map() {
        for (line_no line_num = 0; line_num != lines_of_text.size(); ++line_num)
        {
                istringstream line(lines_of_text[line_num]);
                string word;
                while (line >> word)
                {
                        word_map[word].insert(line_num);
                }
        }
}

std::set<line_no> TextQuery::run_query(const std::string& word) const {       
        map<string, std::set<line_no> >::const_iterator loc = word_map.find(word);
        return (loc == word_map.end() ? set<line_no>() : loc->second);       
}

std::set<line_no> TextQuery::run_query_plus(char ch) const {       

        map<string, std::set<line_no> >::iterator loc;
        for (map<string, std::set<line_no> >::iterator iter = word_map.begin(); iter != word_map.end(); ++iter) {
                if (ch == iter-first[0])
                {
                        loc = iter;
                        break; 
                }
        }
        return (loc == word_map.end() ? set<line_no>() : loc->second);       
}


std::string TextQuery::text_line(line_no line) const {
        if (line < lines_of_text.size())
        {
                return lines_of_text[line];
        }
        throw std::out_of_range("line number out of the range");
}

void print_results(const set<TextQuery::line_no>& locs,
                const string& sought,
                const TextQuery &file) {

        typedef set<TextQuery::line_no> line_nums;
        line_nums::size_type size = locs.size();
//        cout << "\n" << sought << "occurs" << size << " " << make_plural(size, "time", "s") << endl;
        cout << "\n" << sought << " occurs " << size << " time(s)" << endl;

        for (line_nums::const_iterator iter = locs.begin(); iter != locs.end(); ++iter)
        {
                cout << "\t(line " << *iter + 1 << ") " << file.text_line(*iter) << endl;
        }
}

int main0 (int argc, char const* argv[])
{
        ifstream infile("textquery.cpp");
//        if (argc < 2 || !open_file(infile, argv[1]))
        /*
        if (argc < 2 || !infile.open(argv[1]))
        {
                cerr << "No input file!" << endl;
                return EXIT_FAILURE;
        }
        */
        TextQuery tq;
        tq.read_file(infile);
        
        while (true)
        {
                cout << "enter word to look for, or q to quit: ";
                string s;
                cin >> s;
                if (!cin || s == "q" || s == "Q") break;
                
                set<TextQuery::line_no> locs = tq.run_query(s);
                print_results(locs, s , tq);
        }
        
        return 0;
}
