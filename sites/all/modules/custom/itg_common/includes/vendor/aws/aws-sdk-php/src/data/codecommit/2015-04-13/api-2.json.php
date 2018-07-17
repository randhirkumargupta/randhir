<?php
// This file was auto-generated from sdk-root/src/data/codecommit/2015-04-13/api-2.json
return [ 'version' => '2.0', 'metadata' => [ 'apiVersion' => '2015-04-13', 'endpointPrefix' => 'codecommit', 'jsonVersion' => '1.1', 'protocol' => 'json', 'serviceAbbreviation' => 'CodeCommit', 'serviceFullName' => 'AWS CodeCommit', 'signatureVersion' => 'v4', 'targetPrefix' => 'CodeCommit_20150413', 'uid' => 'codecommit-2015-04-13', ], 'operations' => [ 'BatchGetRepositories' => [ 'name' => 'BatchGetRepositories', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'BatchGetRepositoriesInput', ], 'output' => [ 'shape' => 'BatchGetRepositoriesOutput', ], 'errors' => [ [ 'shape' => 'RepositoryNamesRequiredException', ], [ 'shape' => 'MaximumRepositoryNamesExceededException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], ], ], 'CreateBranch' => [ 'name' => 'CreateBranch', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'CreateBranchInput', ], 'errors' => [ [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'RepositoryDoesNotExistException', ], [ 'shape' => 'BranchNameRequiredException', ], [ 'shape' => 'BranchNameExistsException', ], [ 'shape' => 'InvalidBranchNameException', ], [ 'shape' => 'CommitIdRequiredException', ], [ 'shape' => 'CommitDoesNotExistException', ], [ 'shape' => 'InvalidCommitIdException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], ], ], 'CreateRepository' => [ 'name' => 'CreateRepository', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'CreateRepositoryInput', ], 'output' => [ 'shape' => 'CreateRepositoryOutput', ], 'errors' => [ [ 'shape' => 'RepositoryNameExistsException', ], [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'InvalidRepositoryDescriptionException', ], [ 'shape' => 'RepositoryLimitExceededException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], ], ], 'DeleteBranch' => [ 'name' => 'DeleteBranch', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'DeleteBranchInput', ], 'output' => [ 'shape' => 'DeleteBranchOutput', ], 'errors' => [ [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'RepositoryDoesNotExistException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'BranchNameRequiredException', ], [ 'shape' => 'InvalidBranchNameException', ], [ 'shape' => 'DefaultBranchCannotBeDeletedException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], ], ], 'DeleteRepository' => [ 'name' => 'DeleteRepository', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'DeleteRepositoryInput', ], 'output' => [ 'shape' => 'DeleteRepositoryOutput', ], 'errors' => [ [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], ], ], 'GetBlob' => [ 'name' => 'GetBlob', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'GetBlobInput', ], 'output' => [ 'shape' => 'GetBlobOutput', ], 'errors' => [ [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'RepositoryDoesNotExistException', ], [ 'shape' => 'BlobIdRequiredException', ], [ 'shape' => 'InvalidBlobIdException', ], [ 'shape' => 'BlobIdDoesNotExistException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], [ 'shape' => 'FileTooLargeException', ], ], ], 'GetBranch' => [ 'name' => 'GetBranch', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'GetBranchInput', ], 'output' => [ 'shape' => 'GetBranchOutput', ], 'errors' => [ [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'RepositoryDoesNotExistException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'BranchNameRequiredException', ], [ 'shape' => 'InvalidBranchNameException', ], [ 'shape' => 'BranchDoesNotExistException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], ], ], 'GetCommit' => [ 'name' => 'GetCommit', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'GetCommitInput', ], 'output' => [ 'shape' => 'GetCommitOutput', ], 'errors' => [ [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'RepositoryDoesNotExistException', ], [ 'shape' => 'CommitIdRequiredException', ], [ 'shape' => 'InvalidCommitIdException', ], [ 'shape' => 'CommitIdDoesNotExistException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], ], ], 'GetDifferences' => [ 'name' => 'GetDifferences', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'GetDifferencesInput', ], 'output' => [ 'shape' => 'GetDifferencesOutput', ], 'errors' => [ [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'RepositoryDoesNotExistException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'InvalidContinuationTokenException', ], [ 'shape' => 'InvalidMaxResultsException', ], [ 'shape' => 'InvalidCommitIdException', ], [ 'shape' => 'CommitRequiredException', ], [ 'shape' => 'InvalidCommitException', ], [ 'shape' => 'CommitDoesNotExistException', ], [ 'shape' => 'InvalidPathException', ], [ 'shape' => 'PathDoesNotExistException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], ], ], 'GetRepository' => [ 'name' => 'GetRepository', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'GetRepositoryInput', ], 'output' => [ 'shape' => 'GetRepositoryOutput', ], 'errors' => [ [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'RepositoryDoesNotExistException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], ], ], 'GetRepositoryTriggers' => [ 'name' => 'GetRepositoryTriggers', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'GetRepositoryTriggersInput', ], 'output' => [ 'shape' => 'GetRepositoryTriggersOutput', ], 'errors' => [ [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'RepositoryDoesNotExistException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], ], ], 'ListBranches' => [ 'name' => 'ListBranches', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'ListBranchesInput', ], 'output' => [ 'shape' => 'ListBranchesOutput', ], 'errors' => [ [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'RepositoryDoesNotExistException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], [ 'shape' => 'InvalidContinuationTokenException', ], ], ], 'ListRepositories' => [ 'name' => 'ListRepositories', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'ListRepositoriesInput', ], 'output' => [ 'shape' => 'ListRepositoriesOutput', ], 'errors' => [ [ 'shape' => 'InvalidSortByException', ], [ 'shape' => 'InvalidOrderException', ], [ 'shape' => 'InvalidContinuationTokenException', ], ], ], 'PutRepositoryTriggers' => [ 'name' => 'PutRepositoryTriggers', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'PutRepositoryTriggersInput', ], 'output' => [ 'shape' => 'PutRepositoryTriggersOutput', ], 'errors' => [ [ 'shape' => 'RepositoryDoesNotExistException', ], [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'RepositoryTriggersListRequiredException', ], [ 'shape' => 'MaximumRepositoryTriggersExceededException', ], [ 'shape' => 'InvalidRepositoryTriggerNameException', ], [ 'shape' => 'InvalidRepositoryTriggerDestinationArnException', ], [ 'shape' => 'InvalidRepositoryTriggerRegionException', ], [ 'shape' => 'InvalidRepositoryTriggerCustomDataException', ], [ 'shape' => 'MaximumBranchesExceededException', ], [ 'shape' => 'InvalidRepositoryTriggerBranchNameException', ], [ 'shape' => 'InvalidRepositoryTriggerEventsException', ], [ 'shape' => 'RepositoryTriggerNameRequiredException', ], [ 'shape' => 'RepositoryTriggerDestinationArnRequiredException', ], [ 'shape' => 'RepositoryTriggerBranchNameListRequiredException', ], [ 'shape' => 'RepositoryTriggerEventsListRequiredException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], ], ], 'TestRepositoryTriggers' => [ 'name' => 'TestRepositoryTriggers', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'TestRepositoryTriggersInput', ], 'output' => [ 'shape' => 'TestRepositoryTriggersOutput', ], 'errors' => [ [ 'shape' => 'RepositoryDoesNotExistException', ], [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'RepositoryTriggersListRequiredException', ], [ 'shape' => 'MaximumRepositoryTriggersExceededException', ], [ 'shape' => 'InvalidRepositoryTriggerNameException', ], [ 'shape' => 'InvalidRepositoryTriggerDestinationArnException', ], [ 'shape' => 'InvalidRepositoryTriggerRegionException', ], [ 'shape' => 'InvalidRepositoryTriggerCustomDataException', ], [ 'shape' => 'MaximumBranchesExceededException', ], [ 'shape' => 'InvalidRepositoryTriggerBranchNameException', ], [ 'shape' => 'InvalidRepositoryTriggerEventsException', ], [ 'shape' => 'RepositoryTriggerNameRequiredException', ], [ 'shape' => 'RepositoryTriggerDestinationArnRequiredException', ], [ 'shape' => 'RepositoryTriggerBranchNameListRequiredException', ], [ 'shape' => 'RepositoryTriggerEventsListRequiredException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], ], ], 'UpdateDefaultBranch' => [ 'name' => 'UpdateDefaultBranch', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'UpdateDefaultBranchInput', ], 'errors' => [ [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'RepositoryDoesNotExistException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'BranchNameRequiredException', ], [ 'shape' => 'InvalidBranchNameException', ], [ 'shape' => 'BranchDoesNotExistException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], ], ], 'UpdateRepositoryDescription' => [ 'name' => 'UpdateRepositoryDescription', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'UpdateRepositoryDescriptionInput', ], 'errors' => [ [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'RepositoryDoesNotExistException', ], [ 'shape' => 'InvalidRepositoryNameException', ], [ 'shape' => 'InvalidRepositoryDescriptionException', ], [ 'shape' => 'EncryptionIntegrityChecksFailedException', ], [ 'shape' => 'EncryptionKeyAccessDeniedException', ], [ 'shape' => 'EncryptionKeyDisabledException', ], [ 'shape' => 'EncryptionKeyNotFoundException', ], [ 'shape' => 'EncryptionKeyUnavailableException', ], ], ], 'UpdateRepositoryName' => [ 'name' => 'UpdateRepositoryName', 'http' => [ 'method' => 'POST', 'requestUri' => '/', ], 'input' => [ 'shape' => 'UpdateRepositoryNameInput', ], 'errors' => [ [ 'shape' => 'RepositoryDoesNotExistException', ], [ 'shape' => 'RepositoryNameExistsException', ], [ 'shape' => 'RepositoryNameRequiredException', ], [ 'shape' => 'InvalidRepositoryNameException', ], ], ], ], 'shapes' => [ 'AccountId' => [ 'type' => 'string', ], 'AdditionalData' => [ 'type' => 'string', ], 'Arn' => [ 'type' => 'string', ], 'BatchGetRepositoriesInput' => [ 'type' => 'structure', 'required' => [ 'repositoryNames', ], 'members' => [ 'repositoryNames' => [ 'shape' => 'RepositoryNameList', ], ], ], 'BatchGetRepositoriesOutput' => [ 'type' => 'structure', 'members' => [ 'repositories' => [ 'shape' => 'RepositoryMetadataList', ], 'repositoriesNotFound' => [ 'shape' => 'RepositoryNotFoundList', ], ], ], 'BlobIdDoesNotExistException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'BlobIdRequiredException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'BlobMetadata' => [ 'type' => 'structure', 'members' => [ 'blobId' => [ 'shape' => 'ObjectId', ], 'path' => [ 'shape' => 'Path', ], 'mode' => [ 'shape' => 'Mode', ], ], ], 'BranchDoesNotExistException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'BranchInfo' => [ 'type' => 'structure', 'members' => [ 'branchName' => [ 'shape' => 'BranchName', ], 'commitId' => [ 'shape' => 'CommitId', ], ], ], 'BranchName' => [ 'type' => 'string', 'max' => 100, 'min' => 1, ], 'BranchNameExistsException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'BranchNameList' => [ 'type' => 'list', 'member' => [ 'shape' => 'BranchName', ], ], 'BranchNameRequiredException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'ChangeTypeEnum' => [ 'type' => 'string', 'enum' => [ 'A', 'M', 'D', ], ], 'CloneUrlHttp' => [ 'type' => 'string', ], 'CloneUrlSsh' => [ 'type' => 'string', ], 'Commit' => [ 'type' => 'structure', 'members' => [ 'commitId' => [ 'shape' => 'ObjectId', ], 'treeId' => [ 'shape' => 'ObjectId', ], 'parents' => [ 'shape' => 'ParentList', ], 'message' => [ 'shape' => 'Message', ], 'author' => [ 'shape' => 'UserInfo', ], 'committer' => [ 'shape' => 'UserInfo', ], 'additionalData' => [ 'shape' => 'AdditionalData', ], ], ], 'CommitDoesNotExistException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'CommitId' => [ 'type' => 'string', ], 'CommitIdDoesNotExistException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'CommitIdRequiredException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'CommitName' => [ 'type' => 'string', ], 'CommitRequiredException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'CreateBranchInput' => [ 'type' => 'structure', 'required' => [ 'repositoryName', 'branchName', 'commitId', ], 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], 'branchName' => [ 'shape' => 'BranchName', ], 'commitId' => [ 'shape' => 'CommitId', ], ], ], 'CreateRepositoryInput' => [ 'type' => 'structure', 'required' => [ 'repositoryName', ], 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], 'repositoryDescription' => [ 'shape' => 'RepositoryDescription', ], ], ], 'CreateRepositoryOutput' => [ 'type' => 'structure', 'members' => [ 'repositoryMetadata' => [ 'shape' => 'RepositoryMetadata', ], ], ], 'CreationDate' => [ 'type' => 'timestamp', ], 'Date' => [ 'type' => 'string', ], 'DefaultBranchCannotBeDeletedException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'DeleteBranchInput' => [ 'type' => 'structure', 'required' => [ 'repositoryName', 'branchName', ], 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], 'branchName' => [ 'shape' => 'BranchName', ], ], ], 'DeleteBranchOutput' => [ 'type' => 'structure', 'members' => [ 'deletedBranch' => [ 'shape' => 'BranchInfo', ], ], ], 'DeleteRepositoryInput' => [ 'type' => 'structure', 'required' => [ 'repositoryName', ], 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], ], ], 'DeleteRepositoryOutput' => [ 'type' => 'structure', 'members' => [ 'repositoryId' => [ 'shape' => 'RepositoryId', ], ], ], 'Difference' => [ 'type' => 'structure', 'members' => [ 'beforeBlob' => [ 'shape' => 'BlobMetadata', ], 'afterBlob' => [ 'shape' => 'BlobMetadata', ], 'changeType' => [ 'shape' => 'ChangeTypeEnum', ], ], ], 'DifferenceList' => [ 'type' => 'list', 'member' => [ 'shape' => 'Difference', ], ], 'Email' => [ 'type' => 'string', ], 'EncryptionIntegrityChecksFailedException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, 'fault' => true, ], 'EncryptionKeyAccessDeniedException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'EncryptionKeyDisabledException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'EncryptionKeyNotFoundException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'EncryptionKeyUnavailableException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'FileTooLargeException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'GetBlobInput' => [ 'type' => 'structure', 'required' => [ 'repositoryName', 'blobId', ], 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], 'blobId' => [ 'shape' => 'ObjectId', ], ], ], 'GetBlobOutput' => [ 'type' => 'structure', 'required' => [ 'content', ], 'members' => [ 'content' => [ 'shape' => 'blob', ], ], ], 'GetBranchInput' => [ 'type' => 'structure', 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], 'branchName' => [ 'shape' => 'BranchName', ], ], ], 'GetBranchOutput' => [ 'type' => 'structure', 'members' => [ 'branch' => [ 'shape' => 'BranchInfo', ], ], ], 'GetCommitInput' => [ 'type' => 'structure', 'required' => [ 'repositoryName', 'commitId', ], 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], 'commitId' => [ 'shape' => 'ObjectId', ], ], ], 'GetCommitOutput' => [ 'type' => 'structure', 'required' => [ 'commit', ], 'members' => [ 'commit' => [ 'shape' => 'Commit', ], ], ], 'GetDifferencesInput' => [ 'type' => 'structure', 'required' => [ 'repositoryName', 'afterCommitSpecifier', ], 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], 'beforeCommitSpecifier' => [ 'shape' => 'CommitName', ], 'afterCommitSpecifier' => [ 'shape' => 'CommitName', ], 'beforePath' => [ 'shape' => 'Path', ], 'afterPath' => [ 'shape' => 'Path', ], 'MaxResults' => [ 'shape' => 'Limit', ], 'NextToken' => [ 'shape' => 'NextToken', ], ], ], 'GetDifferencesOutput' => [ 'type' => 'structure', 'members' => [ 'differences' => [ 'shape' => 'DifferenceList', ], 'NextToken' => [ 'shape' => 'NextToken', ], ], ], 'GetRepositoryInput' => [ 'type' => 'structure', 'required' => [ 'repositoryName', ], 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], ], ], 'GetRepositoryOutput' => [ 'type' => 'structure', 'members' => [ 'repositoryMetadata' => [ 'shape' => 'RepositoryMetadata', ], ], ], 'GetRepositoryTriggersInput' => [ 'type' => 'structure', 'required' => [ 'repositoryName', ], 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], ], ], 'GetRepositoryTriggersOutput' => [ 'type' => 'structure', 'members' => [ 'configurationId' => [ 'shape' => 'RepositoryTriggersConfigurationId', ], 'triggers' => [ 'shape' => 'RepositoryTriggersList', ], ], ], 'InvalidBlobIdException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidBranchNameException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidCommitException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidCommitIdException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidContinuationTokenException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidMaxResultsException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidOrderException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidPathException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidRepositoryDescriptionException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidRepositoryNameException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidRepositoryTriggerBranchNameException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidRepositoryTriggerCustomDataException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidRepositoryTriggerDestinationArnException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidRepositoryTriggerEventsException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidRepositoryTriggerNameException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidRepositoryTriggerRegionException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'InvalidSortByException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'LastModifiedDate' => [ 'type' => 'timestamp', ], 'Limit' => [ 'type' => 'integer', 'box' => true, ], 'ListBranchesInput' => [ 'type' => 'structure', 'required' => [ 'repositoryName', ], 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], 'nextToken' => [ 'shape' => 'NextToken', ], ], ], 'ListBranchesOutput' => [ 'type' => 'structure', 'members' => [ 'branches' => [ 'shape' => 'BranchNameList', ], 'nextToken' => [ 'shape' => 'NextToken', ], ], ], 'ListRepositoriesInput' => [ 'type' => 'structure', 'members' => [ 'nextToken' => [ 'shape' => 'NextToken', ], 'sortBy' => [ 'shape' => 'SortByEnum', ], 'order' => [ 'shape' => 'OrderEnum', ], ], ], 'ListRepositoriesOutput' => [ 'type' => 'structure', 'members' => [ 'repositories' => [ 'shape' => 'RepositoryNameIdPairList', ], 'nextToken' => [ 'shape' => 'NextToken', ], ], ], 'MaximumBranchesExceededException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'MaximumRepositoryNamesExceededException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'MaximumRepositoryTriggersExceededException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'Message' => [ 'type' => 'string', ], 'Mode' => [ 'type' => 'string', ], 'Name' => [ 'type' => 'string', ], 'NextToken' => [ 'type' => 'string', ], 'ObjectId' => [ 'type' => 'string', ], 'OrderEnum' => [ 'type' => 'string', 'enum' => [ 'ascending', 'descending', ], ], 'ParentList' => [ 'type' => 'list', 'member' => [ 'shape' => 'ObjectId', ], ], 'Path' => [ 'type' => 'string', ], 'PathDoesNotExistException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'PutRepositoryTriggersInput' => [ 'type' => 'structure', 'required' => [ 'repositoryName', 'triggers', ], 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], 'triggers' => [ 'shape' => 'RepositoryTriggersList', ], ], ], 'PutRepositoryTriggersOutput' => [ 'type' => 'structure', 'members' => [ 'configurationId' => [ 'shape' => 'RepositoryTriggersConfigurationId', ], ], ], 'RepositoryDescription' => [ 'type' => 'string', 'max' => 1000, ], 'RepositoryDoesNotExistException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'RepositoryId' => [ 'type' => 'string', ], 'RepositoryLimitExceededException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'RepositoryMetadata' => [ 'type' => 'structure', 'members' => [ 'accountId' => [ 'shape' => 'AccountId', ], 'repositoryId' => [ 'shape' => 'RepositoryId', ], 'repositoryName' => [ 'shape' => 'RepositoryName', ], 'repositoryDescription' => [ 'shape' => 'RepositoryDescription', ], 'defaultBranch' => [ 'shape' => 'BranchName', ], 'lastModifiedDate' => [ 'shape' => 'LastModifiedDate', ], 'creationDate' => [ 'shape' => 'CreationDate', ], 'cloneUrlHttp' => [ 'shape' => 'CloneUrlHttp', ], 'cloneUrlSsh' => [ 'shape' => 'CloneUrlSsh', ], 'Arn' => [ 'shape' => 'Arn', ], ], ], 'RepositoryMetadataList' => [ 'type' => 'list', 'member' => [ 'shape' => 'RepositoryMetadata', ], ], 'RepositoryName' => [ 'type' => 'string', 'max' => 100, 'min' => 1, 'pattern' => '[\\w\\.-]+', ], 'RepositoryNameExistsException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'RepositoryNameIdPair' => [ 'type' => 'structure', 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], 'repositoryId' => [ 'shape' => 'RepositoryId', ], ], ], 'RepositoryNameIdPairList' => [ 'type' => 'list', 'member' => [ 'shape' => 'RepositoryNameIdPair', ], ], 'RepositoryNameList' => [ 'type' => 'list', 'member' => [ 'shape' => 'RepositoryName', ], ], 'RepositoryNameRequiredException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'RepositoryNamesRequiredException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'RepositoryNotFoundList' => [ 'type' => 'list', 'member' => [ 'shape' => 'RepositoryName', ], ], 'RepositoryTrigger' => [ 'type' => 'structure', 'required' => [ 'name', 'destinationArn', 'events', ], 'members' => [ 'name' => [ 'shape' => 'RepositoryTriggerName', ], 'destinationArn' => [ 'shape' => 'Arn', ], 'customData' => [ 'shape' => 'RepositoryTriggerCustomData', ], 'branches' => [ 'shape' => 'BranchNameList', ], 'events' => [ 'shape' => 'RepositoryTriggerEventList', ], ], ], 'RepositoryTriggerBranchNameListRequiredException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'RepositoryTriggerCustomData' => [ 'type' => 'string', ], 'RepositoryTriggerDestinationArnRequiredException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'RepositoryTriggerEventEnum' => [ 'type' => 'string', 'enum' => [ 'all', 'updateReference', 'createReference', 'deleteReference', ], ], 'RepositoryTriggerEventList' => [ 'type' => 'list', 'member' => [ 'shape' => 'RepositoryTriggerEventEnum', ], ], 'RepositoryTriggerEventsListRequiredException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'RepositoryTriggerExecutionFailure' => [ 'type' => 'structure', 'members' => [ 'trigger' => [ 'shape' => 'RepositoryTriggerName', ], 'failureMessage' => [ 'shape' => 'RepositoryTriggerExecutionFailureMessage', ], ], ], 'RepositoryTriggerExecutionFailureList' => [ 'type' => 'list', 'member' => [ 'shape' => 'RepositoryTriggerExecutionFailure', ], ], 'RepositoryTriggerExecutionFailureMessage' => [ 'type' => 'string', ], 'RepositoryTriggerName' => [ 'type' => 'string', ], 'RepositoryTriggerNameList' => [ 'type' => 'list', 'member' => [ 'shape' => 'RepositoryTriggerName', ], ], 'RepositoryTriggerNameRequiredException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'RepositoryTriggersConfigurationId' => [ 'type' => 'string', ], 'RepositoryTriggersList' => [ 'type' => 'list', 'member' => [ 'shape' => 'RepositoryTrigger', ], ], 'RepositoryTriggersListRequiredException' => [ 'type' => 'structure', 'members' => [], 'exception' => true, ], 'SortByEnum' => [ 'type' => 'string', 'enum' => [ 'repositoryName', 'lastModifiedDate', ], ], 'TestRepositoryTriggersInput' => [ 'type' => 'structure', 'required' => [ 'repositoryName', 'triggers', ], 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], 'triggers' => [ 'shape' => 'RepositoryTriggersList', ], ], ], 'TestRepositoryTriggersOutput' => [ 'type' => 'structure', 'members' => [ 'successfulExecutions' => [ 'shape' => 'RepositoryTriggerNameList', ], 'failedExecutions' => [ 'shape' => 'RepositoryTriggerExecutionFailureList', ], ], ], 'UpdateDefaultBranchInput' => [ 'type' => 'structure', 'required' => [ 'repositoryName', 'defaultBranchName', ], 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], 'defaultBranchName' => [ 'shape' => 'BranchName', ], ], ], 'UpdateRepositoryDescriptionInput' => [ 'type' => 'structure', 'required' => [ 'repositoryName', ], 'members' => [ 'repositoryName' => [ 'shape' => 'RepositoryName', ], 'repositoryDescription' => [ 'shape' => 'RepositoryDescription', ], ], ], 'UpdateRepositoryNameInput' => [ 'type' => 'structure', 'required' => [ 'oldName', 'newName', ], 'members' => [ 'oldName' => [ 'shape' => 'RepositoryName', ], 'newName' => [ 'shape' => 'RepositoryName', ], ], ], 'UserInfo' => [ 'type' => 'structure', 'members' => [ 'name' => [ 'shape' => 'Name', ], 'email' => [ 'shape' => 'Email', ], 'date' => [ 'shape' => 'Date', ], ], ], 'blob' => [ 'type' => 'blob', ], ],];
