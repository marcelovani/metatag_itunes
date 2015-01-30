<?php
/**
 * @file
 * Metatag integration for the iTunes metatag.
 */

/**
 * Implements hook_metatag_config_default_alter().
 */
function metatag_itunes_metatag_config_default_alter(array &$configs) {
  foreach ($configs as &$config) {
    switch ($config->instance) {
      case 'global':
      case 'global:frontpage':
      case 'node':
      case 'taxonomy_term':
      case 'user':
        $config->config += array(
          'apple-itunes-app' => array('value' => 'app-id'),
        );
        break;
    }
  }
}

/**
 * Implements hook_metatag_info().
 */
function metatag_itunes_metatag_info() {
  $info['groups']['itunes'] = array(
    'label' => t('Apple iTunes'),
    'description' => t('Meta tag specially for apple iTunes products'),
    'form' => array(
      '#weight' => 60,
    ),
  );

  $info['tags']['apple-itunes-app'] = array(
    'label' => t('app-id or full attribute string'),
    'description' => t('Enter your app-id or a full attribute string eg; app-id=myAppStoreID, affiliate-data=myAffiliateData, app-argument=myURL'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'itunes',
    'element' => array(
      '#theme' => 'metatag_itunes',
    ),
  );
  return $info;
}
