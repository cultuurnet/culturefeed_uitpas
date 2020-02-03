<?php

/**
 * @file
 * Profile implementations for Culturefeed uitpas.
 */

/**
 * Implements hook_culturefeed_ui_profile_sections().
 */
function culturefeed_uitpas_culturefeed_ui_profile_sections() {

  if (culturefeed_uitpas_is_passholder()) {

    // Points.
    $user_info = culturefeed_uitpas_get_uitpas_user();
    /* @var CultureFeed_Uitpas_Passholder $passholder */
    $passholder = $user_info->passholder;

    return array(
      'classes' => array('uitpas'),
      'content' => theme('culturefeed_uitpas_profile_section', array(
        'points_label' => t('Points balance'),
        'points_value' => $passholder->points,
        'links' => 'Beheer je UiTPAS op ' . '<a href="https://www.uitpas.be">UiTPAS.be</a>',
      )),
      'title' => variable_get('culturefeed_uitpas_card_name', 'UiTPAS'),
    );
  }
}
