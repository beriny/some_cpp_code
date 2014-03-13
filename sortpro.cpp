<pre class="prettyprint lang-cpp">#include &lt;iostream&gt;
#include &lt;vector&gt;
#include &lt;algorithm&gt;
#include &lt;iterator&gt;

using namespace std;

int main(void)
{
	typedef vector&lt;int&gt; int_vector;
	typedef istream_iterator&lt;int&gt; istream_itr;
	typedef ostream_iterator&lt;int&gt; ostream_itr;
	typedef back_insert_iterator&lt;int_vector&gt; back_ins_itr;
	
	int_vector num;
	
	copy(istream_itr(cin), istream_itr(), back_ins_itr(num));
	
	sort(num.begin(), num.end());
	copy(num.begin(), num.end(), ostream_itr(cout, " "));
	
	cout &lt;&lt; endl;
	
	return 0;
}
</pre>
