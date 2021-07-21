#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

struct HtmlElement {
    string name, text;
    vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement() {}
    HtmlElement(const string &name, const string &text) 
        : name(name), text(text) {}

    string str(int indent = 0) const {
        ostringstream oss;
        string i(indent_size*indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if (text.size() > 0) {
            oss << string(indent_size*(indent+1), ' ') << text << endl;
        }
        for (const auto& e : elements) {
            oss << e.str(indent + 1);
        }
        oss << i << "</" << name << ">" << endl;
        return oss.str();
    }
};

struct HtmlBuilder {
    HtmlElement root;

    HtmlBuilder () {}
    HtmlBuilder (string root_name) {
        root.name = root_name;
    }

    static HtmlBuilder build(string root_name) {
        return HtmlBuilder{root_name};
    }

    // reference API is better than pointer API
    static unique_ptr<HtmlBuilder> build2(string root_name) {
        return make_unique<HtmlBuilder>(root_name);
    }

    HtmlBuilder& add_child(string child_name, string child_text) {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return *this;
    }

    // reference API is better than the pointer API
    // you have to use -> instread of . if you make a pointer builder
    HtmlBuilder* add_child2(string child_name, string child_text) {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return this;
    }


    operator HtmlElement() const {
        // if you know that this is the last operation 
        // you would do on this builder object, you can do a move instead of a copy 
        // return std::move(root);
        return root;
    }

};

int main (int argc, char *argv[]) {
    auto text = "hello";
    string output;


    HtmlBuilder builder{"ul"};
    HtmlElement element = builder
        .add_child("li", "Adhitha").add_child("li", "Dias");

    cout << element.str();

    auto builder2 = HtmlBuilder::build("ul").add_child("li", "Weerasiri")
        .add_child("li", "Kariyawasam");
    
    cout << builder2.root.str();
    
    return 0;
}