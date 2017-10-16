<?php
namespace Aws\Pinpoint;

use Aws\AwsClient;

/**
 * This client is used to interact with the **Amazon Pinpoint** service.
 * @method \Aws\Result createApp(array $args = [])
 * @method \GuzzleHttp\Promise\Promise createAppAsync(array $args = [])
 * @method \Aws\Result createCampaign(array $args = [])
 * @method \GuzzleHttp\Promise\Promise createCampaignAsync(array $args = [])
 * @method \Aws\Result createImportJob(array $args = [])
 * @method \GuzzleHttp\Promise\Promise createImportJobAsync(array $args = [])
 * @method \Aws\Result createSegment(array $args = [])
 * @method \GuzzleHttp\Promise\Promise createSegmentAsync(array $args = [])
 * @method \Aws\Result deleteAdmChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise deleteAdmChannelAsync(array $args = [])
 * @method \Aws\Result deleteApnsChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise deleteApnsChannelAsync(array $args = [])
 * @method \Aws\Result deleteApnsSandboxChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise deleteApnsSandboxChannelAsync(array $args = [])
 * @method \Aws\Result deleteApp(array $args = [])
 * @method \GuzzleHttp\Promise\Promise deleteAppAsync(array $args = [])
 * @method \Aws\Result deleteBaiduChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise deleteBaiduChannelAsync(array $args = [])
 * @method \Aws\Result deleteCampaign(array $args = [])
 * @method \GuzzleHttp\Promise\Promise deleteCampaignAsync(array $args = [])
 * @method \Aws\Result deleteEmailChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise deleteEmailChannelAsync(array $args = [])
 * @method \Aws\Result deleteEventStream(array $args = [])
 * @method \GuzzleHttp\Promise\Promise deleteEventStreamAsync(array $args = [])
 * @method \Aws\Result deleteGcmChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise deleteGcmChannelAsync(array $args = [])
 * @method \Aws\Result deleteSegment(array $args = [])
 * @method \GuzzleHttp\Promise\Promise deleteSegmentAsync(array $args = [])
 * @method \Aws\Result deleteSmsChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise deleteSmsChannelAsync(array $args = [])
 * @method \Aws\Result getAdmChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getAdmChannelAsync(array $args = [])
 * @method \Aws\Result getApnsChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getApnsChannelAsync(array $args = [])
 * @method \Aws\Result getApnsSandboxChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getApnsSandboxChannelAsync(array $args = [])
 * @method \Aws\Result getApp(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getAppAsync(array $args = [])
 * @method \Aws\Result getApplicationSettings(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getApplicationSettingsAsync(array $args = [])
 * @method \Aws\Result getApps(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getAppsAsync(array $args = [])
 * @method \Aws\Result getBaiduChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getBaiduChannelAsync(array $args = [])
 * @method \Aws\Result getCampaign(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getCampaignAsync(array $args = [])
 * @method \Aws\Result getCampaignActivities(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getCampaignActivitiesAsync(array $args = [])
 * @method \Aws\Result getCampaignVersion(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getCampaignVersionAsync(array $args = [])
 * @method \Aws\Result getCampaignVersions(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getCampaignVersionsAsync(array $args = [])
 * @method \Aws\Result getCampaigns(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getCampaignsAsync(array $args = [])
 * @method \Aws\Result getEmailChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getEmailChannelAsync(array $args = [])
 * @method \Aws\Result getEndpoint(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getEndpointAsync(array $args = [])
 * @method \Aws\Result getEventStream(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getEventStreamAsync(array $args = [])
 * @method \Aws\Result getGcmChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getGcmChannelAsync(array $args = [])
 * @method \Aws\Result getImportJob(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getImportJobAsync(array $args = [])
 * @method \Aws\Result getImportJobs(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getImportJobsAsync(array $args = [])
 * @method \Aws\Result getSegment(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getSegmentAsync(array $args = [])
 * @method \Aws\Result getSegmentImportJobs(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getSegmentImportJobsAsync(array $args = [])
 * @method \Aws\Result getSegmentVersion(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getSegmentVersionAsync(array $args = [])
 * @method \Aws\Result getSegmentVersions(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getSegmentVersionsAsync(array $args = [])
 * @method \Aws\Result getSegments(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getSegmentsAsync(array $args = [])
 * @method \Aws\Result getSmsChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise getSmsChannelAsync(array $args = [])
 * @method \Aws\Result putEventStream(array $args = [])
 * @method \GuzzleHttp\Promise\Promise putEventStreamAsync(array $args = [])
 * @method \Aws\Result sendMessages(array $args = [])
 * @method \GuzzleHttp\Promise\Promise sendMessagesAsync(array $args = [])
 * @method \Aws\Result sendUsersMessages(array $args = [])
 * @method \GuzzleHttp\Promise\Promise sendUsersMessagesAsync(array $args = [])
 * @method \Aws\Result updateAdmChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise updateAdmChannelAsync(array $args = [])
 * @method \Aws\Result updateApnsChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise updateApnsChannelAsync(array $args = [])
 * @method \Aws\Result updateApnsSandboxChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise updateApnsSandboxChannelAsync(array $args = [])
 * @method \Aws\Result updateApplicationSettings(array $args = [])
 * @method \GuzzleHttp\Promise\Promise updateApplicationSettingsAsync(array $args = [])
 * @method \Aws\Result updateBaiduChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise updateBaiduChannelAsync(array $args = [])
 * @method \Aws\Result updateCampaign(array $args = [])
 * @method \GuzzleHttp\Promise\Promise updateCampaignAsync(array $args = [])
 * @method \Aws\Result updateEmailChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise updateEmailChannelAsync(array $args = [])
 * @method \Aws\Result updateEndpoint(array $args = [])
 * @method \GuzzleHttp\Promise\Promise updateEndpointAsync(array $args = [])
 * @method \Aws\Result updateEndpointsBatch(array $args = [])
 * @method \GuzzleHttp\Promise\Promise updateEndpointsBatchAsync(array $args = [])
 * @method \Aws\Result updateGcmChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise updateGcmChannelAsync(array $args = [])
 * @method \Aws\Result updateSegment(array $args = [])
 * @method \GuzzleHttp\Promise\Promise updateSegmentAsync(array $args = [])
 * @method \Aws\Result updateSmsChannel(array $args = [])
 * @method \GuzzleHttp\Promise\Promise updateSmsChannelAsync(array $args = [])
 */
class PinpointClient extends AwsClient {}
