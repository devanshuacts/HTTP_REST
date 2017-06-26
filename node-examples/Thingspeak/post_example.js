const request=require('/home/devanshu/node-v6.10.0/lib/node_modules/request');

var payload = {
	api_key: "P7UOC5M1K1JP5LOH",
	field1:31.6,
	field2:10.9,
	filed3:4.0
};
var jpload = JSON.stringify(payload)
var options={
	uri:"https://api.thingspeak.com/update",
	headers:{
		"Content-type":"application/json"
	},
	body:(jpload)
};

request.post(options, function(err, response, body){
	if(err)
		console.log("error: "+err);
	console.log("status code: "+response.statusCode);
	console.log("response body: "+body);
});
