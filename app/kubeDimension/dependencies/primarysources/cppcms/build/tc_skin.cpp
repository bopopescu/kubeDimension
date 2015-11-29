#line 1 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
#include "tests/tc_test_content.h" 
#line 2 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
namespace tc_skin {
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct test_default_master :public cppcms::base_view
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::master &content;
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		test_default_master(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 3 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 4 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 4 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"c";
		#line 4 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 5 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class test_default_master
	#line 6 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct view_y :public cppcms::base_view
	#line 6 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 6 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::master &content;
	#line 6 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		view_y(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 6 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 6 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"view y";
		#line 7 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 8 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class view_y
	#line 9 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct view_x :public cppcms::base_view
	#line 9 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 9 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::master &content;
	#line 9 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		view_x(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 9 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 9 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 10 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 10 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"view x";
		#line 10 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 11 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class view_x
	#line 12 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct master :public cppcms::base_view
	#line 12 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 12 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::master &content;
	#line 12 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		master(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 12 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 12 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 13 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 15 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"TBD\n"
				"";
		#line 15 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 16 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class master
	#line 18 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct master_tmpl :public cppcms::base_view
	#line 18 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 18 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::master &content;
	#line 18 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		master_tmpl(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 18 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 18 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 19 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void a() {
			#line 19 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"A";
		#line 19 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template a
		#line 20 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void b(int x) {
			#line 20 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"x=";
			#line 20 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(x);
		#line 20 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template b
		#line 21 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void c(int x,std::string const &y) {
			#line 21 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"x=";
			#line 21 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(x);
			#line 21 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<" y=";
			#line 21 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(y);
		#line 21 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template c
		#line 22 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void d(int x,int y) {
			#line 22 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"x=";
			#line 22 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(x);
			#line 22 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<" r=";
			#line 22 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(y);
		#line 22 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template d
		#line 23 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 24 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 24 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			a();
			#line 25 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 25 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			b(10);
			#line 26 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 26 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			b(content.integer);
			#line 27 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 27 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			c(10,"test");
			#line 28 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 28 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			c(content.integer,content.text);
			#line 29 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
		#line 29 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 30 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class master_tmpl
	#line 31 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct foreach_tmpl :public cppcms::base_view
	#line 31 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 31 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::master &content;
	#line 31 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		foreach_tmpl(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 31 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 31 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 32 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void auto_test() {
			#line 33 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 33 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			#ifdef __GNUC__ 
			#line 34 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 34 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).begin()!=(content.integers).end()) {
				#line 34 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(CPPCMS_TYPEOF((content.integers).begin()) x_ptr=(content.integers).begin(),x_ptr_end=(content.integers).end();x_ptr!=x_ptr_end;++x_ptr) {
				#line 34 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				CPPCMS_TYPEOF(*x_ptr) &x=*x_ptr;
					#line 34 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
				#line 34 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
			#line 34 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 35 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 35 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).rbegin()!=(content.integers).rend()) {
				#line 35 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(CPPCMS_TYPEOF((content.integers).rbegin()) x_ptr=(content.integers).rbegin(),x_ptr_end=(content.integers).rend();x_ptr!=x_ptr_end;++x_ptr) {
				#line 35 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				CPPCMS_TYPEOF(*x_ptr) &x=*x_ptr;
					#line 35 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
				#line 35 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
			#line 35 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 36 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 36 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			#endif 
			#line 37 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
		#line 37 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template auto_test
		#line 38 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 38 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			typedef data::master::integers_type::iterator it; typedef data::master::integers_type::reverse_iterator rit;  
			#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).begin()!=(content.integers).end()) {
				#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(it x_ptr=(content.integers).begin(),x_ptr_end=(content.integers).end();x_ptr!=x_ptr_end;++x_ptr) {
				#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< it >::value_type &x=*x_ptr;
				#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				if(x_ptr!=(content.integers).begin()) {
				#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<",";
				#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of separator
					#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
				#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			 } else {
				#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"-";
			#line 39 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // end of empty
			#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).rbegin()!=(content.integers).rend()) {
				#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(rit x_ptr=(content.integers).rbegin(),x_ptr_end=(content.integers).rend();x_ptr!=x_ptr_end;++x_ptr) {
				#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< rit >::value_type &x=*x_ptr;
				#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				if(x_ptr!=(content.integers).rbegin()) {
				#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<",";
				#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of separator
					#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
				#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			 } else {
				#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"-";
			#line 40 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // end of empty
			#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).begin()!=(content.integers).end()) {
			#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 0;
				#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(it x_ptr=(content.integers).begin(),x_ptr_end=(content.integers).end();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< it >::value_type &x=*x_ptr;
				#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				if(x_ptr!=(content.integers).begin()) {
				#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<",";
				#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of separator
					#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			 } else {
				#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"-";
			#line 41 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // end of empty
			#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).rbegin()!=(content.integers).rend()) {
			#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 0;
				#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(rit x_ptr=(content.integers).rbegin(),x_ptr_end=(content.integers).rend();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< rit >::value_type &x=*x_ptr;
				#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				if(x_ptr!=(content.integers).rbegin()) {
				#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<",";
				#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of separator
					#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			 } else {
				#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"-";
			#line 42 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // end of empty
			#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).begin()!=(content.integers).end()) {
			#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 1;
				#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(it x_ptr=(content.integers).begin(),x_ptr_end=(content.integers).end();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< it >::value_type &x=*x_ptr;
				#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				if(x_ptr!=(content.integers).begin()) {
				#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<",";
				#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of separator
					#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			 } else {
				#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"-";
			#line 43 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // end of empty
			#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).rbegin()!=(content.integers).rend()) {
			#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 1;
				#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(rit x_ptr=(content.integers).rbegin(),x_ptr_end=(content.integers).rend();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< rit >::value_type &x=*x_ptr;
				#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				if(x_ptr!=(content.integers).rbegin()) {
				#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<",";
				#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of separator
					#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			 } else {
				#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"-";
			#line 44 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // end of empty
			#line 46 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"\n"
				"";
			#line 46 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).begin()!=(content.integers).end()) {
				#line 46 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 46 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(it x_ptr=(content.integers).begin(),x_ptr_end=(content.integers).end();x_ptr!=x_ptr_end;++x_ptr) {
				#line 46 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< it >::value_type &x=*x_ptr;
					#line 46 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 46 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
				#line 46 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 46 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 46 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			 } else {
				#line 46 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"-";
			#line 46 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // end of empty
			#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).rbegin()!=(content.integers).rend()) {
				#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(rit x_ptr=(content.integers).rbegin(),x_ptr_end=(content.integers).rend();x_ptr!=x_ptr_end;++x_ptr) {
				#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< rit >::value_type &x=*x_ptr;
					#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
				#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			 } else {
				#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"-";
			#line 47 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // end of empty
			#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).begin()!=(content.integers).end()) {
			#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 0;
				#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(it x_ptr=(content.integers).begin(),x_ptr_end=(content.integers).end();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< it >::value_type &x=*x_ptr;
					#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			 } else {
				#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"-";
			#line 48 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // end of empty
			#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).rbegin()!=(content.integers).rend()) {
			#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 0;
				#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(rit x_ptr=(content.integers).rbegin(),x_ptr_end=(content.integers).rend();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< rit >::value_type &x=*x_ptr;
					#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			 } else {
				#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"-";
			#line 49 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // end of empty
			#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).begin()!=(content.integers).end()) {
			#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 1;
				#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(it x_ptr=(content.integers).begin(),x_ptr_end=(content.integers).end();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< it >::value_type &x=*x_ptr;
					#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			 } else {
				#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"-";
			#line 50 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // end of empty
			#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).rbegin()!=(content.integers).rend()) {
			#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 1;
				#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(rit x_ptr=(content.integers).rbegin(),x_ptr_end=(content.integers).rend();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< rit >::value_type &x=*x_ptr;
					#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			 } else {
				#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"-";
			#line 51 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // end of empty
			#line 53 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"\n"
				"";
			#line 53 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).begin()!=(content.integers).end()) {
				#line 53 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 53 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(it x_ptr=(content.integers).begin(),x_ptr_end=(content.integers).end();x_ptr!=x_ptr_end;++x_ptr) {
				#line 53 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< it >::value_type &x=*x_ptr;
				#line 53 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				if(x_ptr!=(content.integers).begin()) {
				#line 53 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<",";
				#line 53 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of separator
					#line 53 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
				#line 53 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 53 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 53 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 54 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 54 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).rbegin()!=(content.integers).rend()) {
				#line 54 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 54 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(rit x_ptr=(content.integers).rbegin(),x_ptr_end=(content.integers).rend();x_ptr!=x_ptr_end;++x_ptr) {
				#line 54 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< rit >::value_type &x=*x_ptr;
				#line 54 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				if(x_ptr!=(content.integers).rbegin()) {
				#line 54 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<",";
				#line 54 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of separator
					#line 54 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
				#line 54 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 54 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 54 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).begin()!=(content.integers).end()) {
			#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 0;
				#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(it x_ptr=(content.integers).begin(),x_ptr_end=(content.integers).end();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< it >::value_type &x=*x_ptr;
				#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				if(x_ptr!=(content.integers).begin()) {
				#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<",";
				#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of separator
					#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 55 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).rbegin()!=(content.integers).rend()) {
			#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 0;
				#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(rit x_ptr=(content.integers).rbegin(),x_ptr_end=(content.integers).rend();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< rit >::value_type &x=*x_ptr;
				#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				if(x_ptr!=(content.integers).rbegin()) {
				#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<",";
				#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of separator
					#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 56 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).begin()!=(content.integers).end()) {
			#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 1;
				#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(it x_ptr=(content.integers).begin(),x_ptr_end=(content.integers).end();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< it >::value_type &x=*x_ptr;
				#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				if(x_ptr!=(content.integers).begin()) {
				#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<",";
				#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of separator
					#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 57 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).rbegin()!=(content.integers).rend()) {
			#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 1;
				#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(rit x_ptr=(content.integers).rbegin(),x_ptr_end=(content.integers).rend();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< rit >::value_type &x=*x_ptr;
				#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				if(x_ptr!=(content.integers).rbegin()) {
				#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<",";
				#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of separator
					#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 58 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 60 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"\n"
				"";
			#line 60 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).begin()!=(content.integers).end()) {
				#line 60 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 60 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(it x_ptr=(content.integers).begin(),x_ptr_end=(content.integers).end();x_ptr!=x_ptr_end;++x_ptr) {
				#line 60 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< it >::value_type &x=*x_ptr;
					#line 60 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 60 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
				#line 60 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 60 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 60 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 61 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 61 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).rbegin()!=(content.integers).rend()) {
				#line 61 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 61 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(rit x_ptr=(content.integers).rbegin(),x_ptr_end=(content.integers).rend();x_ptr!=x_ptr_end;++x_ptr) {
				#line 61 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< rit >::value_type &x=*x_ptr;
					#line 61 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 61 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
				#line 61 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 61 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 61 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 62 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 62 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).begin()!=(content.integers).end()) {
			#line 62 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 0;
				#line 62 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 62 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(it x_ptr=(content.integers).begin(),x_ptr_end=(content.integers).end();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 62 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< it >::value_type &x=*x_ptr;
					#line 62 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 62 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 62 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 62 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 62 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 62 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 62 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 63 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 63 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).rbegin()!=(content.integers).rend()) {
			#line 63 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 0;
				#line 63 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 63 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(rit x_ptr=(content.integers).rbegin(),x_ptr_end=(content.integers).rend();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 63 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< rit >::value_type &x=*x_ptr;
					#line 63 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 63 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 63 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 63 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 63 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 63 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 63 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 64 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 64 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).begin()!=(content.integers).end()) {
			#line 64 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 1;
				#line 64 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 64 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(it x_ptr=(content.integers).begin(),x_ptr_end=(content.integers).end();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 64 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< it >::value_type &x=*x_ptr;
					#line 64 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 64 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 64 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 64 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 64 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 64 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 64 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if((content.integers).rbegin()!=(content.integers).rend()) {
			#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    int y = 1;
				#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"{";
				#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				for(rit x_ptr=(content.integers).rbegin(),x_ptr_end=(content.integers).rend();x_ptr!=x_ptr_end;++x_ptr,++y) {
				#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				std::iterator_traits< rit >::value_type &x=*x_ptr;
					#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(x);
					#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<" ";
					#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
					out()<<cppcms::filters::escape(y);
				#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				} // end of item
				#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"}";
			#line 65 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 66 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
		#line 66 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 67 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class foreach_tmpl
	#line 68 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct master_if :public cppcms::base_view
	#line 68 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 68 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::master &content;
	#line 68 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		master_if(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 68 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 68 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 69 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 70 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 70 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if(content.integer) {
				#line 70 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"integer";
			#line 70 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}else{
				#line 70 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"!integer";
			#line 70 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 71 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 71 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if(!(content.integer)) {
				#line 71 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"!integer";
			#line 71 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}else{
				#line 71 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"!!integer";
			#line 71 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 72 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 72 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if(content.text.empty()) {
				#line 72 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"text empty";
			#line 72 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}else{
				#line 72 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"text not empty";
			#line 72 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 73 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 73 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if(!(content.text.empty())) {
				#line 73 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"!text empty";
			#line 73 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}else{
				#line 73 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"!!text not empty";
			#line 73 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 74 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 74 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if(true) {
				#line 74 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"true";
			#line 74 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // endif
			#line 75 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 75 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if(false) {
				#line 75 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"false";
			#line 75 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // endif
			#line 76 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 76 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if(false) {
				#line 76 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"false";
			#line 76 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 76 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			else
			#line 76 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			if(true) {
				#line 76 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"true";
			#line 76 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			} // endif
			#line 77 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
		#line 77 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 78 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class master_if
	#line 80 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct master_url :public cppcms::base_view
	#line 80 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 80 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::master &content;
	#line 80 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		master_url(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 80 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 80 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 81 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 82 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 82 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			content.app().mapper().map(out(),".");
			#line 83 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 83 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			content.app().mapper().map(out(),".", cppcms::filters::urlencode(content.integer));
			#line 84 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 84 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			content.app().mapper().map(out(),".", cppcms::filters::urlencode(content.integer), cppcms::filters::urlencode(content.text));
			#line 85 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 85 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			content.app().mapper().map(out(),"/", cppcms::filters::urlencode(content.integer));
			#line 86 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 86 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			content.app().mapper().map(out(),"/", cppcms::filters::urlencode(content.integer), cppcms::filters::urlencode(content.text));
			#line 87 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 87 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			content.app().mapper().map(out(),"/", cppcms::filters::urlencode(content.integer), cppcms::filters::raw(content.text));
			#line 88 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 88 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			content.app().mapper().map(out(),"/foo");
			#line 89 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
		#line 89 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 90 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class master_url
	#line 92 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct master_filter :public cppcms::base_view
	#line 92 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 92 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::master &content;
	#line 92 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		master_filter(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 92 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 92 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 93 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 94 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 94 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(content.integer);
			#line 95 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 95 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::locale::format(cppcms::locale::translate("{1,w=3}")) % (cppcms::filters::escape(content.integer));
			#line 96 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 96 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::locale::format(cppcms::locale::translate("{1,w=3} {2}")) % (cppcms::filters::escape(content.integer)) % (cppcms::filters::escape(content.text));
			#line 97 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 97 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::locale::format(cppcms::locale::translate("{1}")) % (cppcms::filters::raw(content.text));
			#line 98 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 98 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::locale::format(cppcms::locale::translate("{1}")) % (content.test_filter(content.text));
			#line 99 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 99 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::locale::format(cppcms::locale::translate("{1}")) % (cppcms::filters::escape(content.test_filter(content.text)));
			#line 100 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 100 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::locale::format(cppcms::locale::translate("{1} {2}")) % (cppcms::filters::escape(content.test_filter(content.text))) % (cppcms::filters::escape(content.integer));
			#line 101 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 101 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(content.text);
			#line 102 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 102 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::raw(content.text);
			#line 103 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 103 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<content.test_filter(content.text);
			#line 104 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 104 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(content.test_filter(content.text));
			#line 105 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 105 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::urlencode(content.text);
			#line 106 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 106 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::base64_urlencode(content.text);
			#line 107 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
		#line 107 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 108 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class master_filter
	#line 110 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct form_test :public cppcms::base_view
	#line 110 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 110 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::form_test &content;
	#line 110 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		form_test(std::ostream &_s,data::form_test &_content): cppcms::base_view(_s),content(_content)
	#line 110 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 110 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 111 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 112 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 112 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.f).render(_form_context); }
			#line 113 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 113 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html);
			#line 113 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    _form_context.widget_part(cppcms::form_context::first_part);
			#line 113 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    (content.t1).render_input(_form_context);
			#line 113 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    out() << (content.t1).attributes_string();
			#line 113 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    _form_context.widget_part(cppcms::form_context::second_part);
			#line 113 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    (content.t1).render_input(_form_context);
			#line 113 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 114 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 114 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html);
			#line 114 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    _form_context.widget_part(cppcms::form_context::first_part);
			#line 114 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    (content.t2).render_input(_form_context);
			#line 114 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    out() << (content.t2).attributes_string();
			#line 114 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    _form_context.widget_part(cppcms::form_context::second_part);
			#line 114 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    (content.t2).render_input(_form_context);
			#line 114 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 115 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 115 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html);
			#line 115 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    _form_context.widget_part(cppcms::form_context::first_part);
			#line 115 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    (content.t2).render_input(_form_context);
			#line 115 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 115 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<" prop ";
			#line 115 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html);
			#line 115 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    _form_context.widget_part(cppcms::form_context::second_part);
			#line 115 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    (content.t2).render_input(_form_context);
			#line 115 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 116 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 116 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html);
			#line 116 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    _form_context.widget_part(cppcms::form_context::first_part);
			#line 116 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    (content.t2).render_input(_form_context);
			#line 116 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
				#line 116 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<" id='x' ";
			#line 116 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html);
			#line 116 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    _form_context.widget_part(cppcms::form_context::second_part);
			#line 116 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    (content.t2).render_input(_form_context);
			#line 116 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 117 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
		#line 117 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 118 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class form_test
	#line 120 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct cache_test :public cppcms::base_view
	#line 120 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 120 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::master &content;
	#line 120 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		cache_test(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 120 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 120 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 121 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 121 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{ std::string _cppcms_temp_val;
			#line 121 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  if(content.app().cache().fetch_frame("key",_cppcms_temp_val))
			#line 121 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			      out() << _cppcms_temp_val;
			#line 121 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  else {
			#line 121 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    cppcms::copy_filter _cppcms_cache_flt(out());
			#line 121 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    cppcms::triggers_recorder _cppcms_trig_rec(content.app().cache());
			#line 121 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    content.call();
				#line 121 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<cppcms::filters::escape(content.integer);
				#line 121 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				content.app().cache().add_trigger("tr");
			#line 121 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    content.app().cache().store_frame("key",_cppcms_cache_flt.detach(),_cppcms_trig_rec.detach(),2,false);
			#line 121 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}} // cache
		#line 121 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 122 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class cache_test
	#line 123 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct cache_test_nr :public cppcms::base_view
	#line 123 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 123 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::master &content;
	#line 123 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		cache_test_nr(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 123 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 123 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 124 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 124 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{ std::string _cppcms_temp_val;
			#line 124 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  if(content.app().cache().fetch_frame("key",_cppcms_temp_val))
			#line 124 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			      out() << _cppcms_temp_val;
			#line 124 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  else {
			#line 124 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    cppcms::copy_filter _cppcms_cache_flt(out());
				#line 124 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<cppcms::filters::escape(content.integer);
				#line 124 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				content.app().cache().add_trigger("tr");
			#line 124 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    content.app().cache().store_frame("key",_cppcms_cache_flt.detach(),std::set<std::string>(),2,false);
			#line 124 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}} // cache
		#line 124 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 125 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class cache_test_nr
	#line 126 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct cache_test_nt :public cppcms::base_view
	#line 126 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 126 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::master &content;
	#line 126 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		cache_test_nt(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 126 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 126 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 127 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 127 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{ std::string _cppcms_temp_val;
			#line 127 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  if(content.app().cache().fetch_frame("key",_cppcms_temp_val))
			#line 127 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			      out() << _cppcms_temp_val;
			#line 127 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  else {
			#line 127 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    cppcms::copy_filter _cppcms_cache_flt(out());
			#line 127 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    cppcms::triggers_recorder _cppcms_trig_rec(content.app().cache());
				#line 127 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<cppcms::filters::escape(content.integer);
			#line 127 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			    content.app().cache().store_frame("key",_cppcms_cache_flt.detach(),_cppcms_trig_rec.detach(),2,true);
			#line 127 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}} // cache
		#line 127 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 128 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class cache_test_nt
	#line 130 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct helper_helper :public cppcms::base_view
	#line 130 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 130 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::helper &content;
	#line 130 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		helper_helper(std::ostream &_s,data::helper &_content): cppcms::base_view(_s),content(_content)
	#line 130 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 130 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 131 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void show_x() {
			#line 131 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(content.x);
			#line 131 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			content.app(); 
		#line 131 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template show_x
		#line 132 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void show_y() {
			#line 132 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(content.y);
		#line 132 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template show_y
		#line 133 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void show_x(int z) {
			#line 133 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(content.x);
			#line 133 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"; ";
			#line 133 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(z);
		#line 133 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template show_x
		#line 134 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void show_y(int z) {
			#line 134 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(content.y);
			#line 134 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"; ";
			#line 134 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(z);
		#line 134 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template show_y
		#line 135 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 135 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"r ";
			#line 135 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(content.x);
			#line 135 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"; ";
			#line 135 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(content.y);
		#line 135 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 136 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class helper_helper
	#line 138 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct helper_master :public cppcms::base_view
	#line 138 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 138 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::master &content;
	#line 138 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		helper_master(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 138 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 138 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 139 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void show_integer() {
			#line 139 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"i ";
			#line 139 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(content.integer);
		#line 139 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template show_integer
		#line 140 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 140 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"ri ";
			#line 140 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<cppcms::filters::escape(content.integer);
		#line 140 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 141 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class helper_master
	#line 143 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	struct test_using :public cppcms::base_view
	#line 143 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	{
	#line 143 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		data::master &content;
	#line 143 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		test_using(std::ostream &_s,data::master &_content): cppcms::base_view(_s),content(_content)
	#line 143 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		{
	#line 143 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		}
		#line 144 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void compilation() {
			#line 145 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 145 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 145 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("tc_skin",content.text,out(),content);
			#line 145 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 146 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 146 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 146 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 146 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("tc_skin",content.text,out(),content.h);
			#line 146 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 147 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 147 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 147 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render(content.text,content.text,out(),content);
			#line 147 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 148 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 148 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 148 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 148 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render(content.text,content.text,out(),content.h);
			#line 148 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 150 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"\n"
				"";
			#line 150 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 150 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("tc_skin","text",out(),content);
			#line 150 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 151 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 151 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 151 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 151 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("tc_skin","text",out(),content.h);
			#line 151 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 152 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 152 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 152 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("text","text",out(),content);
			#line 152 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 153 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 153 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 153 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 153 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("text","text",out(),content.h);
			#line 153 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 155 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"\n"
				"";
			#line 155 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 155 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 155 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("text",content.text,out(),content.h);
			#line 155 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 156 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 156 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 156 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 156 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render(content.text,"text",out(),content.h);
			#line 156 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 157 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 157 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 157 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("text",content.text,out(),content);
			#line 157 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 158 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 158 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 158 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render(content.text,"text",out(),content);
			#line 158 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 160 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"\n"
				"";
			#line 160 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 160 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 160 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("text",content.text,out(),content.h);
			#line 160 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 161 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 161 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 161 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 161 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render(content.text,"text",out(),content.h);
			#line 161 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 162 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 162 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 162 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("text",content.text,out(),content);
			#line 162 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 163 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 163 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 163 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render(content.text,"text",out(),content);
			#line 163 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 165 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"\n"
				"";
			#line 165 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 165 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 165 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("text",content.text,out(),content.h);
			#line 165 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 166 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 166 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 166 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 166 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render(content.text,"text",out(),content.h);
			#line 166 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 167 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 167 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 167 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("text",content.text,out(),content);
			#line 167 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 168 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 168 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 168 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render(content.text,"text",out(),content);
			#line 168 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 170 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"\n"
				"";
			#line 170 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 170 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 170 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("text",content.text,out(),content.h);
			#line 170 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 171 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 171 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 171 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 171 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render(content.text,"text",out(),content.h);
			#line 171 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 172 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 172 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 172 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("text",content.text,out(),content);
			#line 172 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 173 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 173 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 173 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render(content.text,"text",out(),content);
			#line 173 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 177 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"\n"
				"\n"
				"\n"
				"";
		#line 177 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template compilation
		#line 178 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		virtual void render() {
			#line 179 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 179 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 179 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 179 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("tc_skin","helper_helper",out(),content.h);
			#line 179 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 180 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 180 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 180 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("tc_skin","helper_master",out(),content);
			#line 180 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 181 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 181 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 181 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 181 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("tc_skin","helper_helper",out(),content.h);
			#line 181 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 182 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 182 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 182 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::base_content::app_guard _g(content.h,content);
			#line 182 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("tc_skin",content.text,out(),content.h);
			#line 182 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 183 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 183 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 183 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			cppcms::views::pool::instance().render("tc_skin","helper_master",out(),content);
			#line 183 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 184 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 184 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 184 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  cppcms::base_content::app_guard _g(content.h,content);
			#line 184 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  helper_helper hlp(out(),content.h);
				#line 185 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"\n"
					"";
				#line 185 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				hlp.show_x();
				#line 186 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"\n"
					"";
				#line 186 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				hlp.show_y();
				#line 187 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"\n"
					"";
				#line 187 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				hlp.show_x(content.h.y);
				#line 188 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"\n"
					"";
				#line 188 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				hlp.show_y(content.h.x);
				#line 189 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"\n"
					"";
			#line 189 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 190 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 190 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 190 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  helper_master hlp(out(),content);
				#line 191 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"\n"
					"";
				#line 191 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				hlp.show_integer();
				#line 192 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
				out()<<"\n"
					"";
			#line 192 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 193 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 193 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 193 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  cppcms::base_content::app_guard _g(content.h,content);
			#line 193 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  helper_helper _using(out(),content.h);
			#line 193 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			_using.show_x();
			#line 193 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 194 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 194 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 194 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  cppcms::base_content::app_guard _g(content.h,content);
			#line 194 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  helper_helper _using(out(),content.h);
			#line 194 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			_using.show_y();
			#line 194 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 195 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 195 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 195 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  cppcms::base_content::app_guard _g(content.h,content);
			#line 195 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  helper_helper _using(out(),content.h);
			#line 195 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			_using.show_x(content.h.y);
			#line 195 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 196 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 196 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 196 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  cppcms::base_content::app_guard _g(content.h,content);
			#line 196 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  helper_helper _using(out(),content.h);
			#line 196 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			_using.show_y(content.h.x);
			#line 196 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 197 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
			#line 197 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			{
			#line 197 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			  helper_master _using(out(),content);
			#line 197 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			_using.show_integer();
			#line 197 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			}
			#line 198 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
			out()<<"\n"
				"";
		#line 198 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
		} // end of template render
	#line 199 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
	}; // end of class test_using
#line 202 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
} // end of namespace tc_skin
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
namespace {
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
 cppcms::views::generator my_generator; 
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
 struct loader { 
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
  loader() { 
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.name("tc_skin");
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::test_default_master,data::master>("test_default_master",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::view_y,data::master>("view_y",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::view_x,data::master>("view_x",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::master,data::master>("master",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::master_tmpl,data::master>("master_tmpl",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::foreach_tmpl,data::master>("foreach_tmpl",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::master_if,data::master>("master_if",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::master_url,data::master>("master_url",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::master_filter,data::master>("master_filter",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::form_test,data::form_test>("form_test",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::cache_test,data::master>("cache_test",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::cache_test_nr,data::master>("cache_test_nr",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::cache_test_nt,data::master>("cache_test_nt",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::helper_helper,data::helper>("helper_helper",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::helper_master,data::master>("helper_master",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
   my_generator.add_view<tc_skin::test_using,data::master>("test_using",true);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
 }
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
} a_loader;
#line 203 "/src/app/find-object/dependencies/primarysources/cppcms/tests/tc_skin.tmpl"
} // anon 
