<?php
function hook_services_resources() {
  $node_resource = array(
    'node' => array(
      'operations' => array(
        'retrieve' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'services',
                'name' => 'resources/node_resource',
          ), 
          'callback' => '_node_resource_retrieve', 
          'args' => array(
            array(
              'name' => 'nid', 
              'optional' => FALSE, 
              'source' => array('path' => 0), 
              'type' => 'int', 
              'description' => 'The nid of the node to get',
            ),
          ), 
          'access callback' => '_node_resource_access', 
          'access arguments' => array('view'), 
          'access arguments append' => TRUE,
        ), 
        'create' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'services',
            'name' => 'resources/node_resource',
          ), 
          'callback' => '_node_resource_create', 
          'args' => array(
            array(
              'name' => 'node', 
              'optional' => FALSE, 
              'source' => 'data', 
              'description' => 'The node data to create', 
              'type' => 'array',
            ),
          ), 
          'access callback' => '_node_resource_access', 
          'access arguments' => array('create'), 
          'access arguments append' => TRUE,
        ), 
        'update' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'services',
            'name' => 'resources/node_resource',
          ), 
          'callback' => '_node_resource_update', 
          'args' => array(
            array(
              'name' => 'nid', 
              'optional' => FALSE, 
              'source' => array('path' => 0), 
              'type' => 'int', 
              'description' => 'The nid of the node to get',
            ),
            array(
              'name' => 'node', 
              'optional' => FALSE, 
              'source' => 'data', 
              'description' => 'The node data to update', 
              'type' => 'array',
            ),
          ), 
          'access callback' => '_node_resource_access', 
          'access arguments' => array('update'), 
          'access arguments append' => TRUE,
        ), 
        'delete' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'services',
            'name' => 'resources/node_resource',
          ), 
          'callback' => '_node_resource_delete', 
          'args' => array(
            array(
              'name' => 'nid', 
              'optional' => FALSE, 
              'source' => array('path' => 0), 
              'type' => 'int',
            ),
          ), 
          'access callback' => '_node_resource_access', 
          'access arguments' => array('delete'), 
          'access arguments append' => TRUE,
        ), 
        'index' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'services',
            'name' => 'resources/node_resource',
          ), 
          'callback' => '_node_resource_index', 
          'args' => array(
            array(
              'name' => 'page', 
              'optional' => TRUE, 
              'type' => 'int', 
              'description' => 'The zero-based index of the page to get, defaults to 0.', 
              'default value' => 0, 
              'source' => array('param' => 'page'),
            ),
            array(
              'name' => 'fields', 
              'optional' => TRUE, 
              'type' => 'string', 
              'description' => 'The fields to get.', 
              'default value' => '*', 
              'source' => array('param' => 'fields'),
            ),
            array(
              'name' => 'parameters', 
              'optional' => TRUE, 
              'type' => 'array', 
              'description' => 'Parameters array', 
              'default value' => array(), 
              'source' => array('param' => 'parameters'),
            ),
            array(
              'name' => 'pagesize', 
              'optional' => TRUE, 
              'type' => 'int', 
              'description' => 'Number of records to get per page.', 
              'default value' => variable_get('services_node_index_page_size', 20), 
              'source' => array('param' => 'pagesize'),
            ),
          ), 
          'access arguments' => array('access content'),
        ),
      ), 
      'targeted_actions' => array(
        'attach_file' => array(
          'help' => 'Upload and attach file(s) to a node. POST multipart/form-data to node/123/attach_file', 
          'file' => array(
            'type' => 'inc',
            'module' => 'services',
            'name' => 'resources/node_resource',
          ), 
          'callback' => '_node_resource_attach_file', 
          'access callback' => '_node_resource_access', 
          'access arguments' => array('update'), 
          'access arguments append' => TRUE, 
          'args' => array(
            array(
              'name' => 'nid', 
              'optional' => FALSE, 
              'source' => array('path' => 0), 
              'type' => 'int', 
              'description' => 'The nid of the node to attach a file to',
            ),
            array(
              'name' => 'field_name', 
              'optional' => FALSE, 
              'source' => array('data' => 'field_name'), 
              'description' => 'The file parameters', 
              'type' => 'string',
            ),
            array(
              'name' => 'attach', 
              'optional' => TRUE, 
              'source' => array('data' => 'attach'), 
              'description' => 'Attach the file(s) to the node. If FALSE, this clears ALL files attached, and attaches the files', 
              'type' => 'int', 
              'default value' => TRUE,
            ),
            array(
              'name' => 'field_values', 
              'optional' => TRUE, 
              'source' => array('data' => 'field_values'), 
              'description' => 'The extra field values', 
              'type' => 'array', 
              'default value' => array(),
            ),
          ),
        ),
      ), 
      'relationships' => array(
        'files' => array(
          'file' => array(
            'type' => 'inc',
            'module' => 'services',
            'name' => 'resources/node_resource',
          ), 
          'help' => t('This method returns files associated with a node.'), 
          'access callback' => '_node_resource_access', 
          'access arguments' => array('view'), 
          'access arguments append' => TRUE, 
          'callback' => '_node_resource_load_node_files', 
          'args' => array(
            array(
              'name' => 'nid', 
              'optional' => FALSE, 
              'source' => array('path' => 0), 
              'type' => 'int', 
              'description' => 'The nid of the node whose files we are getting',
            ),
            array(
              'name' => 'file_contents', 
              'type' => 'int', 
              'description' => t('To return file contents or not.'), 
              'source' => array('path' => 2), 
              'optional' => TRUE, 
              'default value' => TRUE,
            ),
            array(
              'name' => 'image_styles', 
              'type' => 'int', 
              'description' => t('To return image styles or not.'), 
              'source' => array('path' => 3), 
              'optional' => TRUE, 
              'default value' => FALSE,
            ),
          ),
        ),
      ),
    ),
  );
  if (module_exists('comment')) {
    $comments = array(
      'file' => array(
        'type' => 'inc',
        'module' => 'services',
        'name' => 'resources/node_resource',
      ), 
      'help' => t('This method returns the number of new comments on a given node.'), 
      'access callback' => 'user_access', 
      'access arguments' => array('access comments'), 
      'access arguments append' => FALSE, 
      'callback' => '_node_resource_load_node_comments', 
      'args' => array(
        array(
          'name' => 'nid', 
          'type' => 'int', 
          'description' => t('The node id to load comments for.'), 
          'source' => array('path' => 0), 
          'optional' => FALSE,
        ),
        array(
          'name' => 'count', 
          'type' => 'int', 
          'description' => t('Number of comments to load.'), 
          'source' => array('param' => 'count'), 
          'optional' => TRUE,
        ),
        array(
          'name' => 'offset', 
          'type' => 'int', 
          'description' => t('If count is set to non-zero value, you can pass also non-zero value for start. For example to get comments from 5 to 15, pass count=10 and start=5.'), 
          'source' => array('param' => 'offset'), 
          'optional' => TRUE,
        ),
      ),
    );
    $node_resource['node']['relationships']['comments'] =  $comments;
  }
  return $node_resource;
}

/*
 * 
 * help: Text describing what this callback does.
callback: The name of a function to call when this resource is requested.
file: an array describing the file which contains the callback function
access callback: The name of a function to call to check whether the requesting user has permission to access this resource. If not specified, this defaults to 'user_access'.
access callback file: an array describing the file which contains the access callback function. This attribute only needs to be supplied if the method callback and the access callback are defined in different files, for example when a method callback is overridden using hook_services_resources_alter but the access callback is not
access arguments: The arguments to pass to the access callback.
access arguments append: A boolean indicating whether the resource's arguments should be appended to the access arguments. This can be useful in situations where an access callback is specific to the particular item ('edit all nodes' vs 'edit my nodes'). Defaults to FALSE.
args: an array describing the arguments which should be passed to this resource when it is called. Each element in the array is an associative array containing the following keys:
name: The name of this argument.
type: The data type of this argument (int, string, array)
description: Text describing this argument's usage.
optional: A boolean indicating whether or not this argument is optional.
source: Where this argument should be retrieved from. This can be 'data' (indicating the POST data), 'param' (indicating the query string) or 'path' (indicating the url path). In the case of path, an additional parameter must be passed indicating the index to be used. In the case of 'data' unless you put things in an array, you will get passed to your functions. 'source' => array('data' => 'nid'), will pass them off as a single variable, 'source' => array('data') will give you all argument values to each argument.
default value: this is a value that will be passed to the method for this particular argument if no argument value is passed
 */