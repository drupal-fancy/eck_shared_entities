<?php
/**
 * ECK shared entities selection handler.
 */
class SharedEntities_SelectionHandler extends EntityReference_SelectionHandler_Generic {
  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    return new SharedEntities_SelectionHandler($field, $instance, $entity_type, $entity);
  }

  /**
   * Build an EntityFieldQuery to get referencable entities.
   */
  protected function buildEntityFieldQuery($match = NULL, $match_operator = 'CONTAINS') {
    $query = parent::buildEntityFieldQuery($match, $match_operator);

    $query->propertyCondition('shared', '1');

    if (isset($match)) {
      $query->propertyCondition('shared_title', $match, $match_operator);

      foreach ($query->propertyConditions as $index => $condition) {
        if ($condition['column'] == 'title') {
          unset($query->propertyConditions[$index]);
        }
      }
    }

    return $query;
  }

  /**
   * Implements EntityReferenceHandler::getReferencableEntities().
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    $options = array();
    $entity_type = $this->field['settings']['target_type'];

    $query = $this->buildEntityFieldQuery($match, $match_operator);
    if ($limit > 0) {
      $query->range(0, $limit);
    }

    $results = $query->execute();

    if (!empty($results[$entity_type])) {
      $entities = entity_load($entity_type, array_keys($results[$entity_type]));
      foreach ($entities as $entity_id => $entity) {
        list(,, $bundle) = entity_extract_ids($entity_type, $entity);

        // Use shared entity title when available
        if (isset($entity->shared_title) && trim($entity->shared_title) !== '') {
          $label = trim($entity->shared_title);
        } else {
          $label = $this->getLabel($entity);
        }
        $options[$bundle][$entity_id] = check_plain($label);
      }
    }

    return $options;
  }
}