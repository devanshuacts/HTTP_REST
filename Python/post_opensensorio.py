import requests
import json

url = 'https://realtime.opensensors.io/v1/topics//users/devanshu21/test?client-id=6370&password=8GBVBUKk'
headers = {'Authorization':'api-key a23ba654-b8f2-431b-a593-b7b19e2686ae'}

payload ={'data' : 'test data sent from python application'}

r = requests.post(url, json = payload, headers = headers)

print r.status_code
print r.text
