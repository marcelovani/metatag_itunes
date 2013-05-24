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
    'description' => t('Meta tags specially for apple iTunes products'),
    'form' => array(
      '#weight' => 60,
    ),
  );

  $info['tags']['apple-itunes-app'] = array(
    'label' => t('Apple iTunes app id'),
    'description' => t('Your app-id'),
    'class' => 'DrupalTextMetaTag',
    'group' => 'itunes',
    'context' => array('global'),
    'element' => array(
      '#theme' => 'metatag_itunes',
    ),
  );
  return $info;
}
