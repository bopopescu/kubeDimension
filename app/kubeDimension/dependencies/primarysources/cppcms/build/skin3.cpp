#line 1 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
#include "hello_world_view.h" 
#line 2 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
namespace skin3 {
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
	struct master :public cppcms::base_view
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
	{
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
		view::master &content;
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
		master(std::ostream &_s,view::master &_content): cppcms::base_view(_s),content(_content)
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
		{
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
		}
		#line 4 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
		virtual void render() {
			#line 6 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
			out()<<"\n"
				"\t\t<html>\n"
				"\t\t<title>Skin2:: ";
			#line 6 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
			out()<<cppcms::filters::escape(content.title);
			#line 9 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
			out()<<"</title>\n"
				"\t\t<body>\n"
				"\t\t<h1> Very Cool ;) !!!</h1>\n"
				"\t\t";
			#line 9 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
			body();
			#line 12 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
			out()<<"\n"
				"\t\t</body>\n"
				"\t\t</html>\n"
				"\t";
		#line 12 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
		} // end of template render
		#line 13 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
		virtual void body() {
			#line 14 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
			out()<<"\n"
				"\t";
		#line 14 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
		} // end of template body
	#line 15 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
	}; // end of class master
#line 16 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_skin2.tmpl"
} // end of namespace skin3
#line 2 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
namespace skin3 {
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
	struct csrf :public cppcms::base_view
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
	{
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
		view::csrf &content;
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
		csrf(std::ostream &_s,view::csrf &_content): cppcms::base_view(_s),content(_content)
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
		{
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
		}
		#line 4 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
		virtual void render() {
			#line 5 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"\n"
				"\t\t";
			#line 5 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			if(content.valid) {
				#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<"\n"
					"\t\t\t<p>Valid</p>\n"
					"\t\t";
			#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			}else{
				#line 9 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<"\n"
					"\t\t\t<p>Not Valid</p>\n"
					"\t\t";
			#line 9 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			}
			#line 10 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"\n"
				"\t\t<p> Token: ";
			#line 10 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out() << content.app().session().get_csrf_token();
			#line 11 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"</p>\n"
				"\t\t<p> Cookie name: ";
			#line 11 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out() << content.app().session().get_csrf_token_cookie_name();
			#line 14 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"</p>\n"
				"\t\t<h2>Form Forgery</h2>\n"
				"\t\t<form action=\".\" method=\"post\">\n"
				"\t\t";
			#line 14 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_xhtml,cppcms::form_flags::as_p); (content.my_form).render(_form_context); }
			#line 17 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"\n"
				"\t\t</form>\n"
				"\t\t<h2>Form Post</h2>\n"
				"\t\t<form action=\".\" method=\"post\">";
			#line 17 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out() << "<input type=\"hidden\" name=\"_csrf\" value=\"" << content.app().session().get_csrf_token() <<"\" />\n";
			#line 18 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"\n"
				"\t\t";
			#line 18 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_xhtml,cppcms::form_flags::as_p); (content.my_form).render(_form_context); }
			#line 21 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"\n"
				"\t\t</form>\n"
				"\t\t<h2>Form Script</h2>\n"
				"\t\t<form action=\".\" method=\"post\">";
			#line 21 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out() << "\n"
				"            <script type='text/javascript'>\n"
				"            <!--\n"
				"                {\n"
				"                    var cppcms_cs = document.cookie.indexOf(\""<< content.app().session().get_csrf_token_cookie_name() <<"=\");\n"
				"                    if(cppcms_cs != -1) {\n"
				"                        cppcms_cs += '"<< content.app().session().get_csrf_token_cookie_name() <<"='.length;\n"
				"                        var cppcms_ce = document.cookie.indexOf(\";\",cppcms_cs);\n"
				"                        if(cppcms_ce == -1) {\n"
				"                            cppcms_ce = document.cookie.length;\n"
				"                        }\n"
				"                        var cppcms_token = document.cookie.substring(cppcms_cs,cppcms_ce);\n"
				"                        document.write('<input type=\"hidden\" name=\"_csrf\" value=\"' + cppcms_token + '\" />');\n"
				"                    }\n"
				"                }\n"
				"            -->\n"
				"            </script>\n"
				"            ";
			#line 22 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"\n"
				"\t\t";
			#line 22 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_xhtml,cppcms::form_flags::as_p); (content.my_form).render(_form_context); }
			#line 24 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"\n"
				"\t\t</form>\n"
				"\t";
		#line 24 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
		} // end of template render
	#line 25 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
	}; // end of class csrf
	#line 26 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
	struct hello :public master
	#line 26 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
	{
	#line 26 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
		view::hello &content;
	#line 26 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
		hello(std::ostream &_s,view::hello &_content): master(_s,_content),content(_content)
	#line 26 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
		{
	#line 26 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
		}
		#line 27 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
		virtual void body() {
			#line 31 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"\n"
				"\n"
				"\t<form action=\"\" method=\"post\">\n"
				"\t<ul>\n"
				"\t";
			#line 31 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_xhtml,cppcms::form_flags::as_ul); (content.form).render(_form_context); }
			#line 37 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"\n"
				"\t</ul>\n"
				"\t<input type=\"submit\" value=\"Submit\" />\n"
				"\t</form>\n"
				"\t<form action=\"\" method=\"post\">\n"
				"\t<p>\n"
				"\t\t";
			#line 37 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			if((content.form).begin()!=(content.form).end()) {
				#line 38 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<"\n"
					"\t\t\t";
				#line 38 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				for(cppcms::form::iterator w_ptr=(content.form).begin(),w_ptr_end=(content.form).end();w_ptr!=w_ptr_end;++w_ptr) {
				#line 38 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				std::iterator_traits< cppcms::form::iterator >::value_type &w=*w_ptr;
				#line 38 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				if(w_ptr!=(content.form).begin()) {
				#line 38 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<"<br/>";
				#line 38 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				} // end of separator
					#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					out()<<"\n"
						"\t\t\t\t";
					#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					if(w.has_message()) {
						#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
						out()<<cppcms::filters::escape(w.message());
						#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
						out()<<":";
					#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					} // endif
					#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					out()<<"\n"
						"\t\t\t\t";
					#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_xhtml);
					#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					    _form_context.widget_part(cppcms::form_context::first_part);
					#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					    (w).render_input(_form_context);
					#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					    out() << (w).attributes_string();
					#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					    _form_context.widget_part(cppcms::form_context::second_part);
					#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					    (w).render_input(_form_context);
					#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					}
					#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					out()<<"\n"
						"\t\t\t\t";
					#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					if(!(w.valid())) {
						#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
						out()<<":";
						#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
						out()<<cppcms::filters::escape(w.error_message());
					#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					} // endif
					#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					out()<<"\n"
						"\t\t\t";
				#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				} // end of item
				#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<"\n"
					"\t\t";
			#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			}
			#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"\n"
				"\t\t<input type=\"submit\" value=\"Submit\" />\n"
				"\n"
				"\t</p>\n"
				"\t";
			#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			if((cppcms::locale::translate("LTR").str(out().getloc())=="RTL")) {
			#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			} // endif
			#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"\n"
				"\t\t";
			#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			if(!(content.title.empty())) {
				#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<"<h1>";
				#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<cppcms::filters::escape(content.title);
				#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<"</h1>";
			#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			} // endif
			#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"\n"
				"\t\t<p>";
			#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<cppcms::filters::escape(content.msg);
			#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"</p>\n"
				"\t\t";
			#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			if(!(content.username.empty())) {
				#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<"\n"
					"\t\t<p> The form was: nik=";
				#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<cppcms::filters::escape(content.username);
				#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<", name=";
				#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<cppcms::filters::escape(content.realname);
				#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<", Ok is ";
				#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				if(!(content.ok)) {
					#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					out()<<"not";
				#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				} // endif
				#line 52 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<" checked,\n"
					"\t\t\tpassword=";
				#line 52 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<cppcms::filters::escape(content.password);
				#line 53 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<"</p>\n"
					"\t\t";
			#line 53 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			} // endif
			#line 54 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"\n"
				"\t\t";
			#line 54 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			if((content.numbers).begin()!=(content.numbers).end()) {
				#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<"\n"
					"\t\t\t<ul>\n"
					"\t\t\t";
				#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				for(view::hello::numbers_type::iterator x_ptr=(content.numbers).begin(),x_ptr_end=(content.numbers).end();x_ptr!=x_ptr_end;++x_ptr) {
				#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				std::iterator_traits< view::hello::numbers_type::iterator >::value_type &x=*x_ptr;
					#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					out()<<"\n"
						"\t\t\t<li>";
					#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					out()<<cppcms::locale::format(cppcms::locale::translate("passed one day","passed {1} days",x)) % (cppcms::filters::escape(x));
					#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
					out()<<"</li>\n"
						"\t\t\t";
				#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				} // end of item
				#line 60 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
				out()<<"\n"
					"\t\t\t</ul>\n"
					"\t\t";
			#line 60 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			}
			#line 61 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
			out()<<"\n"
				"\t";
		#line 61 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
		} // end of template body
	#line 62 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
	}; // end of class hello
#line 63 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
} // end of namespace skin3
#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
namespace {
#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
 cppcms::views::generator my_generator; 
#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
 struct loader { 
#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
  loader() { 
#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
   my_generator.name("skin3");
#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
   my_generator.add_view<skin3::master,view::master>("master",true);
#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
   my_generator.add_view<skin3::csrf,view::csrf>("csrf",true);
#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
   my_generator.add_view<skin3::hello,view::hello>("hello",true);
#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
 }
#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
} a_loader;
#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/src/hello_world_view1.tmpl"
} // anon 
