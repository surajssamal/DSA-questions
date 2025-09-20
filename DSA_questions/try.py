#!/bin/python3t


import requests
import json

url = "https://openrouter.ai/api/v1/chat/completions"
headers = {
    "Authorization": "Bearer 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",          # <- real key here
    "Content-Type": "application/json",
    # the next two lines are optional and can be removed
    "HTTP-Referer": "https://example.com",
    "X-Title": "MyTestScript"
}

payload = {
    "model": "deepseek/deepseek-r1-0528:free",
    "messages": [
        {"role": "user", "content": "What is the meaning of life?"}
    ]
}

response = requests.post(url, headers=headers, data=json.dumps(payload))
response.raise_for_status()           # raises an error if request failed

# the assistant’s text is in response.json()["choices"][0]["message"]["content"]
assistant_reply = response.json()["choices"][0]["message"]["content"]
print(assistant_reply)





































