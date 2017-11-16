<?php
// This file was auto-generated from sdk-root/src/data/runtime.lex/2016-11-28/api-2.json
return [ 'version' => '2.0', 'metadata' => [ 'apiVersion' => '2016-11-28', 'endpointPrefix' => 'runtime.lex', 'jsonVersion' => '1.1', 'protocol' => 'rest-json', 'serviceFullName' => 'Amazon Lex Runtime Service', 'signatureVersion' => 'v4', 'signingName' => 'lex', 'uid' => 'runtime.lex-2016-11-28', ], 'operations' => [ 'PostContent' => [ 'name' => 'PostContent', 'http' => [ 'method' => 'POST', 'requestUri' => '/bot/{botName}/alias/{botAlias}/user/{userId}/content', ], 'input' => [ 'shape' => 'PostContentRequest', ], 'output' => [ 'shape' => 'PostContentResponse', ], 'errors' => [ [ 'shape' => 'NotFoundException', ], [ 'shape' => 'BadRequestException', ], [ 'shape' => 'LimitExceededException', ], [ 'shape' => 'InternalFailureException', ], [ 'shape' => 'ConflictException', ], [ 'shape' => 'UnsupportedMediaTypeException', ], [ 'shape' => 'NotAcceptableException', ], [ 'shape' => 'RequestTimeoutException', ], [ 'shape' => 'DependencyFailedException', ], [ 'shape' => 'BadGatewayException', ], [ 'shape' => 'LoopDetectedException', ], ], 'authtype' => 'v4-unsigned-body', ], 'PostText' => [ 'name' => 'PostText', 'http' => [ 'method' => 'POST', 'requestUri' => '/bot/{botName}/alias/{botAlias}/user/{userId}/text', ], 'input' => [ 'shape' => 'PostTextRequest', ], 'output' => [ 'shape' => 'PostTextResponse', ], 'errors' => [ [ 'shape' => 'NotFoundException', ], [ 'shape' => 'BadRequestException', ], [ 'shape' => 'LimitExceededException', ], [ 'shape' => 'InternalFailureException', ], [ 'shape' => 'ConflictException', ], [ 'shape' => 'DependencyFailedException', ], [ 'shape' => 'BadGatewayException', ], [ 'shape' => 'LoopDetectedException', ], ], ], ], 'shapes' => [ 'Accept' => [ 'type' => 'string', ], 'AttributesString' => [ 'type' => 'string', 'sensitive' => true, ], 'BadGatewayException' => [ 'type' => 'structure', 'members' => [ 'Message' => [ 'shape' => 'ErrorMessage', ], ], 'error' => [ 'httpStatusCode' => 502, ], 'exception' => true, ], 'BadRequestException' => [ 'type' => 'structure', 'members' => [ 'message' => [ 'shape' => 'String', ], ], 'error' => [ 'httpStatusCode' => 400, ], 'exception' => true, ], 'BlobStream' => [ 'type' => 'blob', 'streaming' => true, ], 'BotAlias' => [ 'type' => 'string', ], 'BotName' => [ 'type' => 'string', ], 'Button' => [ 'type' => 'structure', 'required' => [ 'text', 'value', ], 'members' => [ 'text' => [ 'shape' => 'ButtonTextStringWithLength', ], 'value' => [ 'shape' => 'ButtonValueStringWithLength', ], ], ], 'ButtonTextStringWithLength' => [ 'type' => 'string', 'max' => 15, 'min' => 1, ], 'ButtonValueStringWithLength' => [ 'type' => 'string', 'max' => 1000, 'min' => 1, ], 'ConflictException' => [ 'type' => 'structure', 'members' => [ 'message' => [ 'shape' => 'String', ], ], 'error' => [ 'httpStatusCode' => 409, ], 'exception' => true, ], 'ContentType' => [ 'type' => 'string', 'enum' => [ 'application/vnd.amazonaws.card.generic', ], ], 'DependencyFailedException' => [ 'type' => 'structure', 'members' => [ 'Message' => [ 'shape' => 'ErrorMessage', ], ], 'error' => [ 'httpStatusCode' => 424, ], 'exception' => true, ], 'DialogState' => [ 'type' => 'string', 'enum' => [ 'ElicitIntent', 'ConfirmIntent', 'ElicitSlot', 'Fulfilled', 'ReadyForFulfillment', 'Failed', ], ], 'ErrorMessage' => [ 'type' => 'string', ], 'GenericAttachment' => [ 'type' => 'structure', 'members' => [ 'title' => [ 'shape' => 'StringWithLength', ], 'subTitle' => [ 'shape' => 'StringWithLength', ], 'attachmentLinkUrl' => [ 'shape' => 'StringUrlWithLength', ], 'imageUrl' => [ 'shape' => 'StringUrlWithLength', ], 'buttons' => [ 'shape' => 'listOfButtons', ], ], ], 'HttpContentType' => [ 'type' => 'string', ], 'IntentName' => [ 'type' => 'string', ], 'InternalFailureException' => [ 'type' => 'structure', 'members' => [ 'message' => [ 'shape' => 'String', ], ], 'error' => [ 'httpStatusCode' => 500, ], 'exception' => true, 'fault' => true, ], 'LimitExceededException' => [ 'type' => 'structure', 'members' => [ 'retryAfterSeconds' => [ 'shape' => 'String', 'location' => 'header', 'locationName' => 'Retry-After', ], 'message' => [ 'shape' => 'String', ], ], 'error' => [ 'httpStatusCode' => 429, ], 'exception' => true, ], 'LoopDetectedException' => [ 'type' => 'structure', 'members' => [ 'Message' => [ 'shape' => 'ErrorMessage', ], ], 'error' => [ 'httpStatusCode' => 508, ], 'exception' => true, ], 'NotAcceptableException' => [ 'type' => 'structure', 'members' => [ 'message' => [ 'shape' => 'String', ], ], 'error' => [ 'httpStatusCode' => 406, ], 'exception' => true, ], 'NotFoundException' => [ 'type' => 'structure', 'members' => [ 'message' => [ 'shape' => 'String', ], ], 'error' => [ 'httpStatusCode' => 404, ], 'exception' => true, ], 'PostContentRequest' => [ 'type' => 'structure', 'required' => [ 'botName', 'botAlias', 'userId', 'contentType', 'inputStream', ], 'members' => [ 'botName' => [ 'shape' => 'BotName', 'location' => 'uri', 'locationName' => 'botName', ], 'botAlias' => [ 'shape' => 'BotAlias', 'location' => 'uri', 'locationName' => 'botAlias', ], 'userId' => [ 'shape' => 'UserId', 'location' => 'uri', 'locationName' => 'userId', ], 'sessionAttributes' => [ 'shape' => 'AttributesString', 'jsonvalue' => true, 'location' => 'header', 'locationName' => 'x-amz-lex-session-attributes', ], 'requestAttributes' => [ 'shape' => 'AttributesString', 'jsonvalue' => true, 'location' => 'header', 'locationName' => 'x-amz-lex-request-attributes', ], 'contentType' => [ 'shape' => 'HttpContentType', 'location' => 'header', 'locationName' => 'Content-Type', ], 'accept' => [ 'shape' => 'Accept', 'location' => 'header', 'locationName' => 'Accept', ], 'inputStream' => [ 'shape' => 'BlobStream', ], ], 'payload' => 'inputStream', ], 'PostContentResponse' => [ 'type' => 'structure', 'members' => [ 'contentType' => [ 'shape' => 'HttpContentType', 'location' => 'header', 'locationName' => 'Content-Type', ], 'intentName' => [ 'shape' => 'IntentName', 'location' => 'header', 'locationName' => 'x-amz-lex-intent-name', ], 'slots' => [ 'shape' => 'String', 'jsonvalue' => true, 'location' => 'header', 'locationName' => 'x-amz-lex-slots', ], 'sessionAttributes' => [ 'shape' => 'String', 'jsonvalue' => true, 'location' => 'header', 'locationName' => 'x-amz-lex-session-attributes', ], 'message' => [ 'shape' => 'Text', 'location' => 'header', 'locationName' => 'x-amz-lex-message', ], 'dialogState' => [ 'shape' => 'DialogState', 'location' => 'header', 'locationName' => 'x-amz-lex-dialog-state', ], 'slotToElicit' => [ 'shape' => 'String', 'location' => 'header', 'locationName' => 'x-amz-lex-slot-to-elicit', ], 'inputTranscript' => [ 'shape' => 'String', 'location' => 'header', 'locationName' => 'x-amz-lex-input-transcript', ], 'audioStream' => [ 'shape' => 'BlobStream', ], ], 'payload' => 'audioStream', ], 'PostTextRequest' => [ 'type' => 'structure', 'required' => [ 'botName', 'botAlias', 'userId', 'inputText', ], 'members' => [ 'botName' => [ 'shape' => 'BotName', 'location' => 'uri', 'locationName' => 'botName', ], 'botAlias' => [ 'shape' => 'BotAlias', 'location' => 'uri', 'locationName' => 'botAlias', ], 'userId' => [ 'shape' => 'UserId', 'location' => 'uri', 'locationName' => 'userId', ], 'sessionAttributes' => [ 'shape' => 'StringMap', ], 'requestAttributes' => [ 'shape' => 'StringMap', ], 'inputText' => [ 'shape' => 'Text', ], ], ], 'PostTextResponse' => [ 'type' => 'structure', 'members' => [ 'intentName' => [ 'shape' => 'IntentName', ], 'slots' => [ 'shape' => 'StringMap', ], 'sessionAttributes' => [ 'shape' => 'StringMap', ], 'message' => [ 'shape' => 'Text', ], 'dialogState' => [ 'shape' => 'DialogState', ], 'slotToElicit' => [ 'shape' => 'String', ], 'responseCard' => [ 'shape' => 'ResponseCard', ], ], ], 'RequestTimeoutException' => [ 'type' => 'structure', 'members' => [ 'message' => [ 'shape' => 'String', ], ], 'error' => [ 'httpStatusCode' => 408, ], 'exception' => true, ], 'ResponseCard' => [ 'type' => 'structure', 'members' => [ 'version' => [ 'shape' => 'String', ], 'contentType' => [ 'shape' => 'ContentType', ], 'genericAttachments' => [ 'shape' => 'genericAttachmentList', ], ], ], 'String' => [ 'type' => 'string', ], 'StringMap' => [ 'type' => 'map', 'key' => [ 'shape' => 'String', ], 'value' => [ 'shape' => 'String', ], 'sensitive' => true, ], 'StringUrlWithLength' => [ 'type' => 'string', 'max' => 2048, 'min' => 1, ], 'StringWithLength' => [ 'type' => 'string', 'max' => 80, 'min' => 1, ], 'Text' => [ 'type' => 'string', 'max' => 1024, 'min' => 1, 'sensitive' => true, ], 'UnsupportedMediaTypeException' => [ 'type' => 'structure', 'members' => [ 'message' => [ 'shape' => 'String', ], ], 'error' => [ 'httpStatusCode' => 415, ], 'exception' => true, ], 'UserId' => [ 'type' => 'string', 'max' => 100, 'min' => 2, 'pattern' => '[0-9a-zA-Z._:-]+', ], 'genericAttachmentList' => [ 'type' => 'list', 'member' => [ 'shape' => 'GenericAttachment', ], 'max' => 10, 'min' => 0, ], 'listOfButtons' => [ 'type' => 'list', 'member' => [ 'shape' => 'Button', ], 'max' => 5, 'min' => 0, ], ],];
