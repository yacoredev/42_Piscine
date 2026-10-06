#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (d_len >= dsize)
		/*
		   7it len 9ad size kaaml dyal dst (w maymknch ykon kbar mno)
		   so mab9atch blasa l '\0'.
		   dema kaykon size > len.
		   dema kareturn d_len + s_len. but fhad l7ala d_len == dsize
		   bach n7do f size kaaml ila jab lah kan d_len > dsize
		   */
		return (s_len + dsize);
	/*
	   otherwise ghaykon len < size fhad l7ala imma:
	   - tb9a dst kima hya.
	   - concate tarf mn src l dest (truncation).
	   - concate src kaml mora dest.
	   w karja3 d_len + s_len
	   */

	i = 0;
	while (src[i] && d_len + i < dsize - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (s_len + d_len);
}
