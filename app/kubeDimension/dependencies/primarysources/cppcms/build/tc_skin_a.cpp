#line 1 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
#include "tests/tc_test_content.h" 
#line 2 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
namespace tc_skin_a {
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
	struct master :public cppcms::base_view
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
	{
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
		data::master &content;
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
		master(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
		{
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
		}
		#line 4 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
		virtual void render() {
			#line 4 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
			out()<<"a";
		#line 4 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
		} // end of template render
	#line 5 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
	}; // end of class master
#line 6 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
} // end of namespace tc_skin_a
#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
namespace {
#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
 cppcms::views::generator my_generator; 
#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
 struct loader { 
#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
  loader() { 
#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
   my_generator.name("tc_skin_a");
#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
   my_generator.add_view<tc_skin_a::master,data::master>("master",true);
#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
 }
#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
} a_loader;
#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin_a.tmpl"
} // anon 
