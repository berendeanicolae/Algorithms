#http://stackoverflow.com/questions/22676/how-do-i-download-a-file-over-http-using-python
#http://stackoverflow.com/questions/3334809/python-urllib2-how-to-send-cookie-with-urlopen-request
#chrome://settings/cookies WC
#https://docs.python.org/2/library/webbrowser.html
import urllib2
import webbrowser

opener = urllib2.build_opener()
opener.addheaders.append(('Cookie', 'WC=7609053-11743-82lhcaEDL1fIZjDC'))
response = opener.open("http://www.wechall.net/challenge/training/programming1/index.php?action=request").read()
webbrowser.open("http://www.wechall.net/challenge/training/programming1/index.php?answer=" + response)