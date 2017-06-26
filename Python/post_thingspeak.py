import requests
import json

url = 'https://api.thingspeak.com/update.json'
headers = {'Content-type':'application/json'}
payload ={
    'api_key': "P7UOC5M1K1JP5LOH",
    'field1':31.6,
    'field2':10.9
}

r = requests.post(url, headers = headers, json = payload)

print r.status_code
print r.text
