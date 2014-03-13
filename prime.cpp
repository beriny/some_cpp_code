<pre class="prettyprint lang-cpp">#include &lt;iostream&gt;

using namespace std;

bool isPrime(const unsigned int&amp; n)
{
	for (unsigned int i = 3; i*i &lt; n; i += 2)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}</pre>
