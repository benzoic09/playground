from pip._vendor import requests

url = requests.get('https://bentechnews.blogspot.com/')
#print(url.text)
#print(url.status_code)
#print(url.headers)

payload = {'page': 2, 'count': 25}
url1 = requests.get('https://httpbin.org/get', params=payload)
#print(url1.text)

payload1 = {'username': 'test', 'password': 'baby'}
url2 = requests.post('https://httpbin.org/post', data=payload1)
#print(url2.text)


url3 = requests.get('https://httpbin.org/basic-auth/alx/baby', auth=('alx','baby'))
print(url3.text)