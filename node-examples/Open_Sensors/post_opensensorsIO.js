const request=require('/home/devanshu/node-v6.10.0/lib/node_modules/request');

var payload = {
	data : "test data sent from node.js application"
};

var jsonpload = JSON.stringify(payload);

var options = {
	url : "https://realtime.opensensors.io/v1/topics//users/devanshu21/test?client-id=6370&password=8GBVBUKk",
	headers : {
		"Content-type":"application/json",
		"Accept":"application/json",
 		"Authorization":"api-key a23ba654-b8f2-431b-a593-b7b19e2686ae"
	},
	body:(jsonpload)
};

request.post(options, function(err, response, body){
	if(err)
		console.log("errornode: "+err);
	console.log("status code: "+response.statusCode);
	console.log("response body: "+body);
});
