Implementation of Text Search Engine

Make search engine for texture search as the following description.

– Given files:

● “word_set.txt”: 5956 key words which can be used in text search.

● “document.txt”: each line of “document.txt” consists of 1000 words which are randomly selected from the 5956 words in “word_set.txt”

– What to do:

● Make function for finding the lines of “document.txt” which contains user input key words.

● Search results should be sorted in the order of your own defined score.

● Measure the elapsed time of each searching process.

● Make function for indexing the “document.txt” for fast search.

– Tips:

● Recommend to use std::map for key word hashing.

● Recommend to use std::vector for postings in a key word.

● Recommend to use your own defined struct or class for a posting. 

– Caution!

● You can use these timing function to measure the elapsed times:

– Linux c++: clock_getting() http://man7.org/linux/man-pages/man2/clock_gettime.2.html

– Windows c++: timeGetTime() http://msdn.microsoft.com/en-us/library/windows/desktop/dd757629(v=vs.85).aspx

– Python: time.time() http://www.tutorialspoint.com/python/time_time.htm
