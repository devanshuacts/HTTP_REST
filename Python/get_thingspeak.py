import requests
import json

headers = {'Content-type':'application/json'}
url = 'https://api.thingspeak.com/channels/279326/status.json?api_key=5SK758COR783LX9S'
r = requests.get(url,headers=headers)

print r.status_code
print r.text
